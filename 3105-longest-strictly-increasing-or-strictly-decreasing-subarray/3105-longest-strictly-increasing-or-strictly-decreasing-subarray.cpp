#include <vector>
#include <algorithm>

class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxLen = 1;
        int incLen = 1;
        int decLen = 1;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                incLen++;
                decLen = 1; // Reset decreasing sequence length
            } else if (nums[i] < nums[i - 1]) {
                decLen++;
                incLen = 1; // Reset increasing sequence length
            } else {
                // If elements are equal, neither strictly increasing nor decreasing
                incLen = 1;
                decLen = 1;
            }
            
            maxLen = std::max({maxLen, incLen, decLen});
        }
        
        return maxLen;
    }
};