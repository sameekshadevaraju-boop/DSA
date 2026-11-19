#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> findMatrix(const std::vector<int>& nums) {
        // Problem constraint: 1 <= nums[i] <= nums.length
        std::vector<int> freq(nums.size() + 1, 0);
        std::vector<std::vector<int>> ans;
        
        for (int num : nums) {
            // If this occurrence exceeds the current number of rows, allocate a new row
            if (freq[num] >= static_cast<int>(ans.size())) {
                ans.emplace_back();
            }
            
            // Place num into the row corresponding to its 0-based occurrence index
            ans[freq[num]].push_back(num);
            freq[num]++;
        }
        
        return ans;
    }
};