#include <vector>
#include <cmath>

class Solution {
private:
    bool canReachOnTime(const std::vector<int>& dist, double hour, int speed) {
        double total_time = 0.0;
        int n = dist.size();
        
        // For all trains except the last, we must wait until the next integer hour
        for (int i = 0; i < n - 1; ++i) {
            // Integer ceiling division: ceil(dist[i] / speed)
            total_time += (dist[i] + speed - 1) / speed;
        }
        
        // The last train does not require waiting for an integer hour
        total_time += static_cast<double>(dist[n - 1]) / speed;
        
        return total_time <= hour;
    }

public:
    int minSpeedOnTime(std::vector<int>& dist, double hour) {
        int n = dist.size();
        
        // Each of the first (n - 1) trains takes at least 1 full hour
        if (hour <= static_cast<double>(n - 1)) {
            return -1;
        }
        
        int left = 1;
        int right = 1e7; // Problem guarantees max answer will not exceed 10^7
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canReachOnTime(dist, hour, mid)) {
                ans = mid;       // Record valid speed and try to find a smaller one
                right = mid - 1;
            } else {
                left = mid + 1;  // Too slow, increase speed
            }
        }
        
        return ans;
    }
};