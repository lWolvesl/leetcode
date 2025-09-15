//
// Created by 李洋 on 2023/10/16.
//

#ifndef LEECODE_C_Q260_H
#define LEECODE_C_Q260_H

#include <vector>
#include <map>

using namespace std;

class Q260 {
public:
    vector<int> singleNumber(vector<int> &nums) {
        unordered_map<int, int> m;
        for (int i: nums) {
            m[i] = m[i] + 1;
        }
        vector<int> ret;
        for (auto [num, count]: m) {
            if (count == 1) {
                if (ret.empty()) {
                    ret.push_back(num);
                } else {
                    ret.push_back(num);
                    return ret;
                }
            }
        }
        return ret;
    }
};

#endif //LEECODE_C_Q260_H
