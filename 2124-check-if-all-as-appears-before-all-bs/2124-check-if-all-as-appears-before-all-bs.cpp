#include <string>

class Solution {
public:
    bool checkString(const std::string& s) {
        // Every 'a' appears before every 'b' iff the substring "ba" never occurs
        return s.find("ba") == std::string::npos;
    }
};