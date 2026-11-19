#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<long long> minOperations(std::vector<int>& nums, std::vector<int>& queries) {
        int n = nums.size();
        
        // 1. Sort nums in-place to partition elements <= query and > query
        std::sort(nums.begin(), nums.end());
        
        // 2. Build 1-indexed prefix sum array using 64-bit integers to prevent overflow
        std::vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        std::vector<long long> ans;
        ans.reserve(queries.size()); // Pre-allocate output buffer
        
        // 3. Answer each query in O(log N) using binary search
        for (int q : queries) {
            // Find the first index where nums[idx] >= q
            long long idx = std::lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            
            // Elements strictly less than q (indices 0 to idx - 1) must be incremented up to q
            long long left_ops = (q * idx) - prefix[idx];
            
            // Elements >= q (indices idx to n - 1) must be decremented down to q
            long long right_ops = (prefix[n] - prefix[idx]) - (q * (n - idx));
            
            ans.push_back(left_ops + right_ops);
        }
        
        return ans;
    }
};