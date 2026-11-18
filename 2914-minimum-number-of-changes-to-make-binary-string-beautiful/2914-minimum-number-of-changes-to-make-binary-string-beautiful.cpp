#include <string>

class Solution {
public:
    int minChanges(const std::string& s) {
        int changes = 0;
        
        // Partition into non-overlapping pairs of length 2: (0,1), (2,3), ...
        // Each pair must contain identical characters to form valid even-length blocks
        for (size_t i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }
        
        return changes;
    }
};