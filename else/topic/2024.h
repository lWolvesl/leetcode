//
// Created by 李洋 on 2023/12/21.
//

#ifndef LEECODE_C_2024_H
#define LEECODE_C_2024_H

#include "stack"

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    bool tag1;
    bool tag2;
};

using namespace std;

int calculate(stack<Node *> S) {
    stack<Node *> temp;
    int num = 0;
    int i = 0;
    while (!S.empty()) {
        num += S.top()->value * pow(10, i++);
        S.pop();
    }
    return num;
}

int get(Node *root) {
    if (!root) {
        return 0;
    }
    int count = 0;
    stack<Node *> S;
    S.push(root);
    while (!S.empty()) {
        if (!S.top()->left && !S.top()->right) {
            count += calculate(S);
        }
        if (S.top()->tag1 == 0 && S.top()->left) {
            S.top()->tag1 = 1;
            S.push(S.top()->left);
            continue;
        }
        if (S.top()->tag2 == 0 && S.top()->left) {
            S.top()->tag2 = 1;
            S.push(S.top()->right);
            continue;
        }
        S.pop();
    }
    return count;
}


#endif //LEECODE_C_2024_H
