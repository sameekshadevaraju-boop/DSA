#include <vector>

class Solution {
public:
    bool validMountainArray(std::vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        
        int i = 0;
        
        // Phase 1: Walk up the strictly increasing slope
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }
        
        // Peak cannot be the first or the last element
        if (i == 0 || i == n - 1) {
            return false;
        }
        
        // Phase 2: Walk down the strictly decreasing slope
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }
        
        // Valid only if we successfully reached the end of the array
        return i == n - 1;
    }
};