//
// Created by 李洋 on 2023/11/3.
//

#ifndef LEECODE_C_Q117_H
#define LEECODE_C_Q117_H

#include <stack>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root) {
    if (!root) {
        return nullptr;
    }
    queue<pair<Node *, int>> Q;
    Q.emplace(root, 1);
    while (!Q.empty()) {
        auto temp = Q.front();
        Q.pop();
        if (temp.second == Q.front().second) {
            temp.first->next = Q.front().first;
        }
        if (temp.first->left != nullptr) {
            Q.emplace(temp.first->left, temp.second + 1);
        }
        if (temp.first->right != nullptr) {
            Q.emplace(temp.first->right, temp.second + 1);
        }
    }
    return root;
}

#endif //LEECODE_C_Q117_H
