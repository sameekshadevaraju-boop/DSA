#include <vector>

class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;
        
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            // If we find an element greater than the next, it's not monotonically increasing
            if (nums[i] > nums[i + 1]) {
                increasing = false;
            }
            // If we find an element smaller than the next, it's not monotonically decreasing
            if (nums[i] < nums[i + 1]) {
                decreasing = false;
            }
        }
        
        // An array is monotonic if it is either entirely increasing or entirely decreasing
        return increasing || decreasing;
    }
};