//
// Created by 李洋 on 2023/10/20.
//

#ifndef LEECODE_C_Q2525_H
#define LEECODE_C_Q2525_H

#include <string>

using namespace std;

class Q2525 {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        if (length >= 10000 || width >= 10000 || height >= 10000 || (long long)length * width * height >= 1000000000) {
            if (mass >= 100) {
                return "Both";
            } else {
                return "Bulky";
            }
        }
        if (mass >= 100) {
            return "Heavy";
        }
        return "Neither";
    }
};

#endif //LEECODE_C_Q2525_H
