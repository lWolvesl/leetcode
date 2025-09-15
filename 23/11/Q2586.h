//
// Created by 李洋 on 2023/11/8.
//

#ifndef LEECODE_C_Q2586_H
#define LEECODE_C_Q2586_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int vowelStrings(vector<string> &words, int left, int right) {
    unordered_map<char, int> m;
    m['a'] = 1;
    m['e'] = 1;
    m['i'] = 1;
    m['o'] = 1;
    m['u'] = 1;
    int count = 0;
    for (int i = left; i <= right; ++i) {
        auto s = words[i];
        if (s != "" && m[s[0]] && m[s[s.length() - 1]]) {
            count++;
        }
    }
    return count;
}

#endif //LEECODE_C_Q2586_H
