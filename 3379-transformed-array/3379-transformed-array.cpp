#include <vector>

class Solution {
public:
    std::vector<int> constructTransformedArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            // Calculate the target index in the circular array.
            // We use ((... % n + n) % n) to correctly handle negative modulo results in C++.
            int target = ((i + nums[i]) % n + n) % n;
            ans[i] = nums[target];
        }
        
        return ans;
    }
};