#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int maxDistance(std::vector<std::vector<int>>& arrays) {
        int res = 0;
        int min_val = arrays[0].front();
        int max_val = arrays[0].back();
        
        // Iterate starting from the second array
        for (size_t i = 1; i < arrays.size(); ++i) {
            // The distance can be between current array's max and previous min, 
            // or previous max and current array's min.
            res = std::max({res, std::abs(arrays[i].back() - min_val), std::abs(max_val - arrays[i].front())});
            
            // Update the global min and max using the current array's endpoints
            min_val = std::min(min_val, arrays[i].front());
            max_val = std::max(max_val, arrays[i].back());
        }
        
        return res;
    }
};