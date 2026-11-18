#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSkips(std::vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        const long long INF = 1e15;
        
        // dp[j] = minimum total distance-equivalent (time * speed) after processing 
        // roads up to index i using exactly j skips.
        std::vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            long long d = dist[i];
            
            // Iterate backwards to update in-place using only 1D O(N) memory
            for (int j = i + 1; j >= 0; --j) {
                // Option 1: Do NOT skip the rest after road i (only valid if j <= i)
                // Wait time rounds total distance-equivalent up to the next multiple of speed
                long long no_skip = INF;
                if (j <= i && dp[j] != INF) {
                    long long total = dp[j] + d;
                    // For the last road (i == n - 1), no waiting is required after arrival
                    if (i < n - 1) {
                        no_skip = ((total + speed - 1) / speed) * speed;
                    } else {
                        no_skip = total;
                    }
                }
                
                // Option 2: Skip the rest after road i (requires j >= 1)
                long long do_skip = INF;
                if (j >= 1 && dp[j - 1] != INF) {
                    do_skip = dp[j - 1] + d;
                }
                
                dp[j] = std::min(no_skip, do_skip);
            }
        }
        
        // Multiply hoursBefore by speed to compare directly in integer distance units
        long long max_allowed_dist = static_cast<long long>(hoursBefore) * speed;
        
        for (int j = 0; j <= n; ++j) {
            if (dp[j] <= max_allowed_dist) {
                return j;
            }
        }
        
        return -1;
    }
};