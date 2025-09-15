//
// Created by 李洋 on 2023/10/19.
//

#ifndef LEECODE_C_COMBINATION_H
#define LEECODE_C_COMBINATION_H

#include <iostream>
#include <vector>

// 计算组合数 C(n, m)
int calculateCnm(int n, int m) {
    if (m < 0 || m > n) {
        return 0;
    }
    if (m > n / 2) {
        m = n - m;  // 优化，使用较小的 m 提高效率
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= std::min(i, m); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

#endif //LEECODE_C_COMBINATION_H
