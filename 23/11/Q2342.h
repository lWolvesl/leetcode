#ifndef LEECODE_C_Q2342_H
#define LEECODE_C_Q2342_H

#include <vector>
#include <map>
using namespace std;

int maximumSum(vector<int> &nums)
{
    int ans = -1;
    int mx[82]{}; // 至多 9 个 9 相加
    for (int num : nums)
    {
        int s = 0; // num 的数位和
        for (int x = num; x; x /= 10)
        { // 枚举 num 的每个数位
            s += x % 10;
        }
        if (mx[s])
        {                                // 说明左边也有数位和等于 s 的元素
            ans = max(ans, mx[s] + num); // 更新答案的最大值
        }
        mx[s] = max(mx[s], num); // 维护数位和等于 s 的最大元素
    }
    return ans;
}

#endif LEECODE_C_Q2342_H