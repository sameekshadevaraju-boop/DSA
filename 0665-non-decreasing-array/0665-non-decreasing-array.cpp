#include <vector>

class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                count++;
                if (count > 1) {
                    return false;
                }
                
                // Decide whether to modify nums[i] or nums[i + 1]
                if (i > 0 && nums[i - 1] > nums[i + 1]) {
                    // If the element before nums[i] is greater than nums[i + 1],
                    // we cannot lower nums[i]. We must raise nums[i + 1] to match nums[i].
                    nums[i + 1] = nums[i];
                } else {
                    // Otherwise, it's safer/better to lower nums[i] to match nums[i + 1]
                    // (This also covers the case when i == 0).
                    nums[i] = nums[i + 1];
                }
            }
        }
        
        return true;
    }
};