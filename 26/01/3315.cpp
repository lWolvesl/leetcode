#include <vector>

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        std::vector<int> ans;
        for(auto num:nums){
            if (num == 2) {
                ans.push_back(-1);
                continue;
            }
            int temp = num;
            int t=0;
            while (temp & 1) {
                t++;
                temp >>= 1;
            }
            ans.push_back(num ^ (1 << (t-1)));
        }
        return ans;
    }
};