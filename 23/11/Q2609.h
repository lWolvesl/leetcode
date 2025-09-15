//
// Created by 李洋 on 2023/11/8.
//

#ifndef LEECODE_C_Q2609_H
#define LEECODE_C_Q2609_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

int findTheLongestBalancedSubstring(string s) {
    int n = s.size(), idx = 0, ans = 0;
    while (idx < n) {
        int a = 0, b = 0;
        while (idx < n && s[idx] == '0' && ++a >= 0) idx++;
        while (idx < n && s[idx] == '1' && ++b >= 0) idx++;
        ans = max(ans, min(a, b) * 2);
    }
    return ans;
}

#endif //LEECODE_C_Q2609_H
