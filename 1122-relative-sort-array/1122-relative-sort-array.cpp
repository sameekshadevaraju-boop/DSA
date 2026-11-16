#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        // Find the maximum element to size the frequency array tightly
        int maxVal = *std::max_element(arr1.begin(), arr1.end());
        std::vector<int> count(maxVal + 1, 0);
        
        // 1. Count frequencies of all elements in arr1
        for (int num : arr1) {
            count[num]++;
        }
        
        std::vector<int> ans;
        ans.reserve(arr1.size()); // Pre-allocate memory to prevent reallocations
        
        // 2. Place elements that appear in arr2 in their exact relative order
        for (int num : arr2) {
            while (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }
        
        // 3. Place remaining elements (not in arr2) in ascending order
        for (int num = 0; num <= maxVal; ++num) {
            while (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }
        
        return ans;
    }
};