#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;
        
        // Iterate through all possible starting points of the subarray
        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            for (int j = i; j < n; ++j) {
                currentSum += nums[j];
                int len = j - i + 1;
                
                // Check if the current length is within the range [l, r]
                if (len >= l && len <= r) {
                    if (currentSum > 0) {
                        minSum = std::min(minSum, currentSum);
                    }
                } 
                // If the length exceeds 'r', no need to continue expanding this subarray
                else if (len > r) {
                    break;
                }
            }
        }
        
        // If minSum wasn't updated, no valid positive-sum subarray exists
        return (minSum == INT_MAX) ? -1 : minSum;
    }
};