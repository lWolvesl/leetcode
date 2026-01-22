#include <string>

class Solution {
public:
    int vowelConsonantScore(std::string s) {
        int v =0,c=0;
        std::string col = "aeiou";
        for (auto i : s) {
            if (i > 122 || i < 97) {
                continue;
            }
            if (col.find(i) != std::string::npos) {
                v++;
            }else {
                c++;
            }
        }
        if (c==0) {
            return 0;
        }
        return v/c;
    }
};