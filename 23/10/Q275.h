//
// Created by 李洋 on 2023/10/30.
//

#ifndef LEECODE_C_Q275_H
#define LEECODE_C_Q275_H

#include <vector>

using namespace std;

class Q275 {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};

#endif //LEECODE_C_Q275_H
