#include <vector>
#include <algorithm>
#include <random>

class Solution {
private:
    std::vector<int> original;
    std::vector<int> current;
    std::mt19937 rng;

public:
    Solution(std::vector<int>& nums) {
        original = nums;
        current = nums;
        // Seed the random number generator
        std::random_device rd;
        rng.seed(rd());
    }
    
    std::vector<int> reset() {
        current = original;
        return current;
    }
    
    std::vector<int> shuffle() {
        int n = current.size();
        // Fisher-Yates Shuffle Algorithm
        for (int i = n - 1; i > 0; --i) {
            std::uniform_int_distribution<int> dist(0, i);
            int j = dist(rng);
            std::swap(current[i], current[j]);
        }
        return current;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */