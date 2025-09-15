//
// Created by 李洋 on 2023/10/12.
//

#ifndef LEECODE_C_Q2526_H
#define LEECODE_C_Q2526_H

#include <vector>

using namespace std;

class Q2526 {
public:
    long long findTheArrayConcVal(vector<int> &nums) {
        long long ans = 0;
        for (int i = 0, j = nums.size() - 1; i <= j; i++, j--) {
            if (i != j) {
                int temp = nums[j];
                int digit = 0;
                while (temp != 0) {
                    digit++;
                    temp /= 10;
                }
                ans += nums[j] + (long long) nums[i] * pow(10, digit);
            } else {
                ans += nums[i];
            }
        }
        return ans;
    }
};

#endif //LEECODE_C_Q2526_H
