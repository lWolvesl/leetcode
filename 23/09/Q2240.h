//
// Created by 李洋 on 2023/9/1.
//

#ifndef LEECODE_C_2240_H
#define LEECODE_C_2240_H

class Q2240 {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long count = total / cost2 + 1;
        int tos = total / cost1;
        for (int i = 1; i <= tos; ++i) {
            int temp = total - i * cost1;
            count += temp / cost2 + 1;
        }
        return count;
    }
};

#endif //LEECODE_C_2240_H
