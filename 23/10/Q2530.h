//
// Created by 李洋 on 2023/10/18.
//

#ifndef LEECODE_C_Q2530_H
#define LEECODE_C_Q2530_H

#include <vector>
#include <queue>

using namespace std;

long long maxKelements(vector<int> &nums, int k) {
    long long count = 0;
    priority_queue<int> Q(nums.begin(), nums.end());
    while (k) {
        auto top = Q.top();
        Q.pop();
        count += top;
        Q.push(ceil(top / 3.0));
        k--;
    }
    return count;
}

#endif //LEECODE_C_Q2530_H
