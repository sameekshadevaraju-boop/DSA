#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        // Map to store the first occurrence of each prefix sum
        std::unordered_map<int, int> sumMap;
        // Base case: prefix sum 0 occurs at index -1
        sumMap[0] = -1;
        
        int maxLength = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Treat 0 as -1 and 1 as +1
            count += (nums[i] == 1) ? 1 : -1;
            
            // If this prefix sum has been seen before, it means the subarray 
            // between that index and current index has an equal number of 0s and 1s.
            if (sumMap.find(count) != sumMap.end()) {
                maxLength = std::max(maxLength, i - sumMap[count]);
            } else {
                // Store the first time we see this prefix sum
                sumMap[count] = i;
            }
        }
        
        return maxLength;
    }
};