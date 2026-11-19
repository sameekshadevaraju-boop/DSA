#include <vector>
#include <algorithm>

class Solution {
public:
    int minimizeSum(std::vector<int>& nums) {
        int n = nums.size();
        
        // Sorting lets us inspect the smallest and largest boundary elements
        std::sort(nums.begin(), nums.end());
        
        // Low score can always be made 0 by setting one modified element equal to another.
        // To minimize the high score (max - min), we eliminate 2 extreme elements across 3 cases:
        // 1. Change the two smallest elements -> new range is [nums[2], nums[n - 1]]
        int case1 = nums[n - 1] - nums[2];
        
        // 2. Change the two largest elements -> new range is [nums[0], nums[n - 3]]
        int case2 = nums[n - 3] - nums[0];
        
        // 3. Change one smallest and one largest element -> new range is [nums[1], nums[n - 2]]
        int case3 = nums[n - 2] - nums[1];
        
        return std::min({case1, case2, case3});
    }
};