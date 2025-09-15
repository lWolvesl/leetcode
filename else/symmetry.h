//
// Created by 李洋 on 2023/10/4.
//

#ifndef LEECODE_C_SYMMETRY_H
#define LEECODE_C_SYMMETRY_H

#include <string>
#include <stack>

bool isSymmetry(std::string target) {
    std::stack<char> tk;
    for (int i = 0; i < target.length(); ++i) {
        if (i < target.length() / 2) {
            tk.push(target[i]);
        }
        if (i == target.length() / 2 && target.length() % 2 == 1) {
            i++;
        }
        if (i >= target.length() / 2) {
            if (target[i] != tk.top()) {
                return false;
            }
            tk.pop();
        }
    }
    return true;
}

#endif //LEECODE_C_SYMMETRY_H
