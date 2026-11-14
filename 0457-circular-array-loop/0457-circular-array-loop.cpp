#include <vector>

class Solution {
public:
    bool circularArrayLoop(std::vector<int>& nums) {
        int n = nums.size();
        // 0: unvisited, positive (trav_id): visiting in current path, -1: processed/invalid
        std::vector<int> visited(n, 0);

        auto getNextIndex = [&](int i) {
            return ((i + nums[i]) % n + n) % n;
        };

        for (int i = 0; i < n; ++i) {
            if (visited[i] != 0) continue;

            int curr = i;
            int trav_id = i + 1; // Unique identifier for the current traversal path

            while (true) {
                // Check if direction changes (all numbers in the cycle must have the same sign)
                if (nums[curr] * nums[i] < 0) {
                    break;
                }

                if (visited[curr] == trav_id) {
                    // Cycle detected! Now verify if its length is greater than 1
                    int next = getNextIndex(curr);
                    if (curr == next) {
                        // Self-loop of length 1 is invalid
                        break;
                    }
                    return true;
                }

                if (visited[curr] != 0) {
                    // Hit a node from a previous traversal
                    break;
                }

                visited[curr] = trav_id;
                curr = getNextIndex(curr);
            }

            // Mark all nodes in this failed path as -1 so we don't re-traverse them
            curr = i;
            while (visited[curr] == trav_id) {
                int next = getNextIndex(curr);
                visited[curr] = -1;
                curr = next;
            }
        }

        return false;
    }
};