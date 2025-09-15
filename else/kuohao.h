//
// Created by 李洋 on 2023/10/4.
//

#ifndef LEECODE_C_KUOHAO_H
#define LEECODE_C_KUOHAO_H

#include <string>
#include <stack>

bool isKuoHao(std::string target) {
    std::stack<char> tk;
    for (int i = 0; i < target.length(); ++i) {
        if (tk.empty()) {
            tk.push(target[i]);
            continue;
        }
        char temp;
        switch (target[i]) {
            case '{':
                temp = '}';
                break;
            case '}':
                temp = '{';
                break;
            case '[':
                temp = ']';
                break;
            case ']':
                temp = '[';
                break;
            case '(':
                temp = ')';
                break;
            case ')':
                temp = '(';
                break;
            default:
                temp = 'x';
        }
        if (temp == tk.top()) {
            tk.pop();
        } else {
            tk.push(target[i]);
        }
    }
    return tk.empty();
}

// cout << isKuoHao("{}(({}))") << endl;

#endif //LEECODE_C_KUOHAO_H
