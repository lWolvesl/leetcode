//
// Created by 李洋 on 2023/10/26.
//

#ifndef LEECODE_C_2520_H
#define LEECODE_C_2520_H

#include <string>

using namespace std;

class Q2520 {
public:
    int countDigits(int num) {
        string str = to_string(num);
        int res = 0;
        for (auto &ch: str) {
            if (num % (ch - '0') == 0) {
                res++;
            }
        }
        return res;
    }
};

#endif //LEECODE_C_2520_H
