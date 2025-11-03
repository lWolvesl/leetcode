#include <vector>
using namespace std;

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    if(k == 1 && nums.size() > 1){
        return true;
    }
    vector<int> s;
    int temp = 1;
    for(int i = 1;i<nums.size();++i){
        if(nums[i] > nums[i-1]){
            temp++;
            if(temp >= 2 * k){
                return true;
            }
            continue;
        }
        if(temp >= k){
            s.push_back(temp);
            if(s.size() > 1){
                return true;
            }
            temp = 1;
            continue;
        }
        while (s.size() > 0)
        {
            s.pop_back();
        }
        temp = 1;
    }
    return false;
}