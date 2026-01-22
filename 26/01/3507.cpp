#include <climits>
#include <vector>

class Solution {
public:
    bool isIncrease(std::vector<int>& nums){
        for (int i = 1; i<nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                return false;
            }
        }
        return true;
    }

    int minimumPairRemoval(std::vector<int>& nums) {
        int ans = 0;
        while (!isIncrease(nums)) {
            int index = 0;
            int minX = INT_MAX;
            for (int i = 0; i< nums.size()-1; i++) {
                int temp = nums[i]+nums[i+1];
                if (minX > temp) {
                    minX = temp;
                    index = i;
                }
            }
            nums.erase(nums.begin()+index+1);
            nums[index] = minX;
            ans++;
        }
        return ans;
    }
};