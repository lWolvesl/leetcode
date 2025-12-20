#include <unordered_map>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        int count = 0;
        for(auto num: nums){
            m[num] ++;
            if (m[num] > 1) {
                count++;
            }
        }
        if(count == 0){
            return 0;
        }
        int ans = 0;
        for (int i = 0; i<nums.size(); i++) {
            if (m[nums[i]] > 1) {
                m[nums[i]]--;
                count--;
            }
            if ((i + 1) % 3 == 0) {
                ans++;
            }
            if (count == 0) {
                if ((i + 1) % 3 != 0) {
                    ans++;
                }
                break;
            }
        }
        return ans;
    }
};