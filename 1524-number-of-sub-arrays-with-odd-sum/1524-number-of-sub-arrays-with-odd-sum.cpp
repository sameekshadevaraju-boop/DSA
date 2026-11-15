#include <vector>

class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr) {
        long long odd_count = 0;
        long long even_count = 1; // Base case: prefix sum of 0 is even
        long long current_prefix_sum = 0;
        long long ans = 0;
        const int MOD = 1e9 + 7;

        for (int num : arr) {
            current_prefix_sum += num;
            
            // If the current prefix sum is odd, it forms an odd-sum subarray 
            // when paired with any previous even prefix sum.
            if (current_prefix_sum % 2 != 0) {
                ans = (ans + even_count) % MOD;
                odd_count++;
            } 
            // If the current prefix sum is even, it forms an odd-sum subarray 
            // when paired with any previous odd prefix sum.
            else {
                ans = (ans + odd_count) % MOD;
                even_count++;
            }
        }

        return ans;
    }
};