//
// Created by 李洋 on 2023/10/25.
//

#ifndef LEECODE_C_Q2698_H
#define LEECODE_C_Q2698_H

#include <vector>

using namespace std;

class Q2698 {
public:
    int punishmentNumber(int n) {
        auto all = vector<int>(
                {1, 9, 10, 36, 45, 55, 82, 91, 99, 100, 235, 297, 369, 370, 379, 414, 657, 675, 703, 756, 792, 909, 918,
                 945, 964, 990, 991, 999, 1000});
        int count = 0;
        for (int i = 0; i < all.size() && all[i] <= n; ++i) {
            count += all[i] * all[i];
        }
        return count;
    }
};

#endif //LEECODE_C_Q2698_H
