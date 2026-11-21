#include <vector>
#include <string>
#include <array>

class Solution {
public:
    std::vector<int> findSubtreeSizes(const std::vector<int>& parent, const std::string& s) {
        int n = parent.size();

        // 1. Build a flat Compressed Sparse Row (CSR) adjacency list for the original tree
        // Avoids N separate heap allocations of std::vector<std::vector<int>>
        std::vector<int> head(n, -1);
        std::vector<int> to(n, -1);
        std::vector<int> next_edge(n, -1);
        int edge_idx = 0;

        for (int i = 1; i < n; ++i) {
            to[edge_idx] = i;
            next_edge[edge_idx] = head[parent[i]];
            head[parent[i]] = edge_idx++;
        }

        // 2. Track the deepest active ancestor node for each character 'a'..'z' during DFS
        std::array<int, 26> last_seen;
        last_seen.fill(-1);

        std::vector<int> sub_size(n, 1);

        // 3. Single DFS pass simultaneously re-parents nodes and accumulates final subtree sizes
        auto dfs = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev_ancestor = last_seen[c];

            // Record u as the closest active ancestor with character s[u] for its descendants
            last_seen[c] = u;

            for (int e = head[u]; e != -1; e = next_edge[e]) {
                int v = to[e];
                self(self, v);

                // If an ancestor with character s[v] exists, v attaches to the deepest one;
                // otherwise, v stays attached to its original parent u.
                int effective_parent = (last_seen[s[v] - 'a'] != -1) ? last_seen[s[v] - 'a'] : u;
                sub_size[effective_parent] += sub_size[v];
            }

            // Backtrack: restore the previous ancestor state upon leaving u's subtree
            last_seen[c] = prev_ancestor;
        };

        dfs(dfs, 0);
        return sub_size;
    }
};