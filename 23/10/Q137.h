//
// Created by 李洋 on 2023/10/16.
//

#ifndef LEECODE_C_Q137_H
#define LEECODE_C_Q137_H

#include <vector>
#include <map>

using namespace std;

class Q137 {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> m;
        for (int i: nums) {
            m[i] = m[i] + 1;
        }
        for (auto [num, count]: m) {
            if (count == 1) {
                return num;
            }
        }
        return -1;
    }
};

#endif //LEECODE_C_Q137_H
