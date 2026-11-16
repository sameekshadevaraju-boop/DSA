#include <string>

class Solution {
public:
    std::string digitSum(std::string s, int k) {
        // Keep reducing the string until its length is at most k
        while (s.length() > k) {
            std::string next_s;
            
            // Process the string in chunks of size k
            for (size_t i = 0; i < s.length(); i += k) {
                int sum = 0;
                
                // Sum the digits in the current group (up to k characters)
                for (size_t j = i; j < i + k && j < s.length(); ++j) {
                    sum += s[j] - '0';
                }
                
                // Append the string representation of the group's sum
                next_s += std::to_string(sum);
            }
            
            // Update s for the next round
            s = std::move(next_s);
        }
        
        return s;
    }
};