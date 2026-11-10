#include <vector>

class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        long long miss = 1; // The smallest sum that cannot be formed yet
        int patches = 0;    // Count of patches added
        int i = 0;          // Index for nums vector
        int sz = nums.size();
        
        while (miss <= n) {
            // If the current number in nums is less than or equal to 'miss',
            // we can form all numbers up to miss + nums[i] - 1.
            if (i < sz && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } else {
                // Otherwise, we must patch the array with 'miss'
                miss += miss;
                patches++;
            }
        }
        
        return patches;
    }
};