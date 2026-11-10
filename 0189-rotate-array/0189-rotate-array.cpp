#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k is greater than the array size
        if (k == 0) return;
        
        // Step 1: Reverse the entire array
        std::reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse the first k elements
        std::reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse the remaining n - k elements
        std::reverse(nums.begin() + k, nums.end());
    }
};