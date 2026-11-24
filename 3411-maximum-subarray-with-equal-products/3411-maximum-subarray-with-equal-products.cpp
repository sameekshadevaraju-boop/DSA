#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                prod *= x;
                g = (j == i) ? x : std::gcd(g, x);
                l = (l / std::gcd(l, x)) * x;

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }

                // Since l <= 2520 for nums[k] <= 10 and g >= 1,
                // l * g is at most 2520 * g (and never exceeds 2520 * prod).
                if (prod > 2520LL * 2520LL) {
                    break;
                }
            }
        }

        return ans;
    }
};