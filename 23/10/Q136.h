//
// Created by 李洋 on 2023/10/14.
//

#ifndef LEECODE_C_Q136_H
#define LEECODE_C_Q136_H

#include <vector>

using namespace std;

class Q136 {
public:
    int singleNumber(vector<int> &nums) {
        int count = 0;
        for (int i: nums) {
            count ^= i;
        }
        return count;
    }
};

#endif //LEECODE_C_Q136_H
