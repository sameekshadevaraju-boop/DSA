#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> ans;
        ans.reserve(2 * n); // Pre-allocate exact memory to avoid heap reallocations
        
        for (int i = 0; i < n; ++i) {
            ans.push_back(nums[i]);     // Add x_i
            ans.push_back(nums[i + n]); // Add y_i
        }
        
        return ans;
    }
};