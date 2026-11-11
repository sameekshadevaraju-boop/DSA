#include <vector>
#include <algorithm>

class Solution {
public:
    int arrayNesting(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<bool> visited(n, false);
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            // If the element hasn't been visited, traverse its cycle
            if (!visited[i]) {
                int count = 0;
                int curr = i;
                
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = nums[curr];
                    count++;
                }
                
                maxLength = std::max(maxLength, count);
            }
        }

        return maxLength;
    }
};