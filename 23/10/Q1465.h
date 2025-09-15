//
// Created by 李洋 on 2023/10/27.
//

#ifndef LEECODE_C_Q1465_H
#define LEECODE_C_Q1465_H

#include <vector>

using namespace std;

class Q1465 {
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        int maxHorizon;
        int maxVertical;

        if (horizontalCuts.size()) {
            maxHorizon = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]);
        } else {
            maxHorizon = h;
        }
        if (verticalCuts.size()) {
            maxVertical = max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]);
        } else {
            maxVertical = w;
        }

        for (int i = 1; i < horizontalCuts.size(); ++i) {
            maxHorizon = max(maxHorizon, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        for (int i = 1; i < verticalCuts.size(); ++i) {
            maxVertical = max(maxVertical, verticalCuts[i] - verticalCuts[i - 1]);
        }

        return (long long) maxHorizon * maxVertical % 1000000001;
    }
};

#endif //LEECODE_C_Q1465_H
