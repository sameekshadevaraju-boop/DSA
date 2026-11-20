#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSelectedElements(std::vector<int>& nums) {
        // Sort ascending so smaller elements are processed before larger ones
        std::sort(nums.begin(), nums.end());
        
        // Max possible value after incrementing by 1 is nums.back() + 1 (up to 10^6 + 1)
        int max_val = nums.back() + 1;
        
        // dp[v] = longest consecutive sequence ending at value v
        std::vector<int> dp(max_val + 1, 0);
        int max_len = 1;
        
        for (int x : nums) {
            // Evaluate (x + 1) BEFORE (x) so an element doesn't chain onto itself
            // (i.e., using both x and x + 1 from the same single element)
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            
            max_len = std::max({max_len, dp[x], dp[x + 1]});
        }
        
        return max_len;
    }
};