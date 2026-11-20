#include <vector>

class Solution {
public:
    std::vector<bool> isArraySpecial(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        
        // prefix_violations[i] stores the count of adjacent pairs with identical parity in nums[0...i]
        std::vector<int> prefix_violations(n, 0);
        
        for (int i = 1; i < n; ++i) {
            // Bitwise check: ((a ^ b) & 1) == 0 means both are even or both are odd (a violation)
            int violation = (((nums[i - 1] ^ nums[i]) & 1) == 0) ? 1 : 0;
            prefix_violations[i] = prefix_violations[i - 1] + violation;
        }
        
        std::vector<bool> ans;
        ans.reserve(queries.size()); // Pre-allocate output buffer to avoid heap reallocations
        
        for (const auto& q : queries) {
            int from = q[0];
            int to = q[1];
            
            // Subarray nums[from...to] is special iff there are zero violations between from and to
            ans.push_back((prefix_violations[to] - prefix_violations[from]) == 0);
        }
        
        return ans;
    }
};