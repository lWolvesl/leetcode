#include <climits>
#include <vector>

class Solution {
public:
    long long maxSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long long> sum(n+1);
        sum[0] = 0;
        for(int i = 0;i<n;i++){
            sum[i+1] = sum[i] + nums[i]; 
        }

        std::vector<long long> mins(k,LLONG_MAX/2);
        long long ans = LLONG_MIN;
        for(int j = 0;j < n + 1;j++){
            int i = j%k;
            ans = std::max(ans,sum[j]-mins[i]);
            mins[i] = std::min(mins[i],sum[j]);
        }
        return ans;
    }

    long long maxSubarraySumByDP(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long long> sum(n + 1);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        std::vector<long long> dp(n + 1,-1);
        long long ans = -1e18;
        for (int i = k; i <= n; ++i) {
            dp[i] = std::max(dp[i - k], (long long)0) + sum[i] - sum[i - k];
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};