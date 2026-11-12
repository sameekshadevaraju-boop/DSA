#include <vector>

class Solution {
public:
    std::vector<int> beautifulArray(int n) {
        if (n == 1) {
            return {1};
        }
        
        // Recursively generate beautiful arrays for odds and evens
        std::vector<int> odds = beautifulArray((n + 1) / 2);
        std::vector<int> evens = beautifulArray(n / 2);
        
        std::vector<int> res;
        
        // Transform and place odd elements on the left: (2 * x - 1)
        for (int x : odds) {
            res.push_back(2 * x - 1);
        }
        
        // Transform and place even elements on the right: (2 * x)
        for (int x : evens) {
            res.push_back(2 * x);
        }
        
        return res;
    }
};