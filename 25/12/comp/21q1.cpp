#include <string>

class Solution {
public:
    int mirrorDistance(int n) {
        std::string s = std::to_string(n);
        std::reverse(s.begin(),s.end());
        return std::abs(n - std::stoi(s));
    }
};