#include <unordered_map>
#include <vector>

class Solution {
public:
    int minSwaps(std::vector<int>& nums, std::vector<int>& forbidden) {
        std::unordered_map<int, int> m1,m2;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            m1[nums[i]]++;
            m2[nums[i]]++;
        }
        for(auto [k,v] : m1){
            if (v + m2[k] > n)
            {
                return -1;
            }
        }
        // ❎未完成
    }
};