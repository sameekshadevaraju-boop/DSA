#include <vector>
#include <array>

class Solution {
public:
    std::vector<long long> resultArray(const std::vector<int>& nums, int k) {
        std::vector<long long> ans(k, 0);
        
        // k <= 5 per problem constraints, so fixed-size arrays sit completely in L1 cache/registers
        std::array<long long, 5> prev_dp{};
        
        for (int num : nums) {
            std::array<long long, 5> curr_dp{};
            int mod_val = num % k;
            
            // 1. Start a brand new subarray consisting solely of `num`
            curr_dp[mod_val] += 1;
            
            // 2. Extend every non-empty subarray ending at the previous index
            for (int r = 0; r < k; ++r) {
                if (prev_dp[r] > 0) {
                    int next_r = (r * mod_val) % k;
                    curr_dp[next_r] += prev_dp[r];
                }
            }
            
            // 3. Accumulate counts of all subarrays ending at the current index into the global answer
            for (int r = 0; r < k; ++r) {
                ans[r] += curr_dp[r];
            }
            
            prev_dp = curr_dp;
        }
        
        return ans;
    }
};