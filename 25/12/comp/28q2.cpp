#include <algorithm>
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (costBoth >= cost1 + cost2) {
            return (long long)cost1 * need1 + (long long)cost2 * need2;
        }
        int m1 = std::min(need1,need2);
        long long a2 = (long long)std::max(need1,need2) * costBoth;
        long long ans = (long long)m1 * costBoth;
        ans += (long long)(need1 - m1) * cost1;
        ans += (long long)(need2 - m1) * cost2;
        return std::min(ans,a2);
    }
};