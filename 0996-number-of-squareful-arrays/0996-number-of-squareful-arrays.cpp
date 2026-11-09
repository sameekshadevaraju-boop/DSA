#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
private:
    bool isSquare(int num) {
        int root = round(sqrt(num));
        return root * root == num;
    }

    void backtrack(std::vector<int>& nums, std::vector<bool>& visited, std::vector<int>& path, int& count) {
        if (path.size() == nums.size()) {
            count++;
            return;
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            // Skip already visited elements
            if (visited[i]) continue;
            
            // Skip duplicates to avoid duplicate permutations
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            // If path is not empty, check if the sum with the previous element is a square
            if (!path.empty() && !isSquare(path.back() + nums[i])) continue;

            // Choose
            visited[i] = true;
            path.push_back(nums[i]);

            // Explore
            backtrack(nums, visited, path, count);

            // Un-choose (Backtrack)
            path.pop_back();
            visited[i] = false;
        }
    }

public:
    int numSquarefulPerms(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<bool> visited(nums.size(), false);
        std::vector<int> path;
        int count = 0;

        backtrack(nums, visited, path, count);
        return count;
    }
};