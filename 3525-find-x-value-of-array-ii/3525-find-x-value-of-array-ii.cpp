#include <vector>
#include <array>

class Solution {
private:
    struct Node {
        int prod = 1;
        std::array<int, 5> cnt{}; // cnt[r] = number of prefixes in this segment with product % k == r
    };

    int k;
    int n;
    std::vector<Node> tree;

    // Combines left child segment and right child segment in O(K)
    Node merge(const Node& left, const Node& right) const {
        Node res;
        res.prod = (left.prod * right.prod) % k;
        res.cnt = left.cnt;

        // Every prefix of the right segment is multiplied by left.prod
        for (int r = 0; r < k; ++r) {
            if (right.cnt[r] > 0) {
                int combined_r = (left.prod * r) % k;
                res.cnt[combined_r] += right.cnt[r];
            }
        }
        return res;
    }

    // Builds the segment tree in O(N * K)
    void build(const std::vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            int rem = nums[start] % k;
            tree[node].prod = rem;
            tree[node].cnt.fill(0);
            tree[node].cnt[rem] = 1;
            return;
        }

        int mid = start + ((end - start) >> 1);
        int left_child = node << 1;
        int right_child = left_child | 1;

        build(nums, left_child, start, mid);
        build(nums, right_child, mid + 1, end);
        tree[node] = merge(tree[left_child], tree[right_child]);
    }

    // Point update at index `idx` in O(K log N)
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % k;
            tree[node].prod = rem;
            tree[node].cnt.fill(0);
            tree[node].cnt[rem] = 1;
            return;
        }

        int mid = start + ((end - start) >> 1);
        int left_child = node << 1;
        int right_child = left_child | 1;

        if (idx <= mid) {
            update(left_child, start, mid, idx, val);
        } else {
            update(right_child, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[left_child], tree[right_child]);
    }

    // Range query on [ql, qr] in O(K log N)
    Node query(int node, int start, int end, int ql, int qr) const {
        if (ql <= start && end <= qr) {
            return tree[node];
        }

        int mid = start + ((end - start) >> 1);
        int left_child = node << 1;
        int right_child = left_child | 1;

        if (qr <= mid) {
            return query(left_child, start, mid, ql, qr);
        }
        if (ql > mid) {
            return query(right_child, mid + 1, end, ql, qr);
        }

        return merge(
            query(left_child, start, mid, ql, qr),
            query(right_child, mid + 1, end, ql, qr)
        );
    }

public:
    std::vector<int> resultArray(const std::vector<int>& nums, int k, const std::vector<std::vector<int>>& queries) {
        this->k = k;
        this->n = static_cast<int>(nums.size());

        // Single contiguous vector allocation for the entire segment tree
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);

        std::vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // 1. Apply the persistent point update nums[index] = value
            update(1, 0, n - 1, index, value);

            // 2. Query the suffix [start, n - 1]; its prefix products correspond to
            //    all subarrays starting at `start` (i.e., removing prefix [0, start - 1] and any suffix)
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};