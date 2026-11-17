#include <string>
#include <vector>

class Solution {
public:
    int numberOfArrays(std::string s, int k) {
        int n = s.length();
        const int MOD = 1e9 + 7;
        
        // dp[i] represents the number of valid arrays that can be formed from suffix s[i...n-1]
        std::vector<int> dp(n + 1, 0);
        dp[n] = 1; // Base case: 1 way to restore an empty suffix
        
        // Iterate backwards from the end of the string
        for (int i = n - 1; i >= 0; --i) {
            // Leading zeros are not allowed in positive integers
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            
            long long num = 0;
            // Extend the current integer substring s[i...j] while it remains <= k
            for (int j = i; j < n; ++j) {
                num = num * 10 + (s[j] - '0');
                
                // Since digits are non-negative, once num > k, any further extension will also exceed k
                if (num > k) {
                    break;
                }
                
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
        
        return dp[0];
    }
};