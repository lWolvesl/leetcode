//
// Created by 李洋 on 2023/10/29.
//

#ifndef LEECODE_C_Q274_H
#define LEECODE_C_Q274_H

#include <vector>

using namespace std;

class Q274 {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end(), [](int a, int b) {
            return a > b;
        });
        for (int i = 1; i < citations.size(); ++i) {
            if (citations[i - 1] < i) {
                return i - 1;
            }
            if (i + 1 == citations.size() - 1) {
                return i + 1;
            }
        }
        return citations[0] == 0 ? 0 : 1;
    }
};

#endif //LEECODE_C_Q274_H
