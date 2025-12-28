#include <algorithm>
#include <climits>
#include <vector>
class Solution {
public:
    long long maximumScore(std::vector<int>& nums) {
        std::vector<long long> pre;
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pre.push_back(sum);
        }
        int mins = nums[n - 1];
        long long ans = pre[n-2] - mins;
        for (int i = n - 3; i >= 0; i--) {
            mins = std::min(mins,nums[i+1]);
            ans = std::max(ans,pre[i] - mins);
        }
        return ans;
    }
};