#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumChanges(std::string s, int k) {
        int n = s.length();
        const int INF = 1e9;
        
        // Precompute proper divisors for all possible substring lengths (2 to n)
        std::vector<std::vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d * d <= len; ++d) {
                if (len % d == 0) {
                    if (d < len) divisors[len].push_back(d);
                    if (d * d != len && (len / d) < len) {
                        divisors[len].push_back(len / d);
                    }
                }
            }
        }
        
        // cost[i][j] = minimum changes to turn substring s[i...j] into a semi-palindrome
        std::vector<std::vector<int>> cost(n, std::vector<int>(n, INF));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_ops = INF;
                
                // Test every valid modulo step d
                for (int d : divisors[len]) {
                    int ops = 0;
                    // Check each of the d interleaved subsequences
                    for (int rem = 0; rem < d; ++rem) {
                        int l = i + rem;
                        int r = j - (d - 1 - rem);
                        while (l < r) {
                            if (s[l] != s[r]) {
                                ops++;
                            }
                            l += d;
                            r -= d;
                        }
                    }
                    min_ops = std::min(min_ops, ops);
                }
                cost[i][j] = min_ops;
            }
        }
        
        // dp[parts][i] = min changes to partition prefix s[0...i-1] into 'parts' semi-palindromes
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n + 1, INF));
        dp[0][0] = 0;
        
        for (int parts = 1; parts <= k; ++parts) {
            // Each semi-palindrome must have length >= 2, so index i starts at 2 * parts
            for (int i = 2 * parts; i <= n; ++i) {
                // Previous split point m must allow (parts - 1) segments of length >= 2
                for (int m = 2 * (parts - 1); m <= i - 2; ++m) {
                    if (dp[parts - 1][m] != INF) {
                        dp[parts][i] = std::min(dp[parts][i], dp[parts - 1][m] + cost[m][i - 1]);
                    }
                }
            }
        }
        
        return dp[k][n];
    }
};