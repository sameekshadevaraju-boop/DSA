#include <vector>

class Solution {
public:
    bool isArraySpecial(const std::vector<int>& nums) {
        // Check every adjacent pair for differing parity (one even, one odd)
        for (size_t i = 1; i < nums.size(); ++i) {
            // Bitwise XOR of LSBs equals 1 iff parities differ; 0 if they match
            if (((nums[i - 1] ^ nums[i]) & 1) == 0) {
                return false;
            }
        }
        
        return true;
    }
};