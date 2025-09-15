//
// Created by 李洋 on 2024/1/22.
//

#ifndef LEECODE_C_670_H
#define LEECODE_C_670_H

#include <string>

using namespace std;

int maximumSwap(int num) {
    string charArray = to_string(num);
    int n = charArray.size();
    int maxIdx = n - 1;
    int idx1 = -1, idx2 = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (charArray[i] > charArray[maxIdx]) {
            maxIdx = i;
        } else if (charArray[i] < charArray[maxIdx]) {
            idx1 = i;
            idx2 = maxIdx;
        }
    }
    if (idx1 >= 0) {
        swap(charArray[idx1], charArray[idx2]);
        return stoi(charArray);
    } else {
        return num;
    }
}

#endif //LEECODE_C_670_H
