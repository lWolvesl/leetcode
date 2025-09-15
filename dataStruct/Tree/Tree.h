//
// Created by 李洋 on 2023/8/14.
//

#ifndef LEECODE_C_TREE_H
#define LEECODE_C_TREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <random>
#include <queue>

TreeNode *creatRandomTree(int size) {
    if (size == 0) {
        return nullptr;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    std::queue<int> Q;
    std::queue<TreeNode *> T;
    for (int i = size; i > 0; --i) {
        Q.push(dis(gen));
        std::cout << Q.back() << " ";
    }
    std::cout << std::endl;

    TreeNode *head = new TreeNode(Q.front());
    T.push(head);
    Q.pop();

    while (!Q.empty()) {
        if (T.front()->left != nullptr && T.front()->right != nullptr) {
            T.pop();
        }

        TreeNode *temp = new TreeNode(Q.front());
        Q.pop();

        if (T.front()->left == nullptr) {
            T.front()->left = temp;
            T.push(temp);
            continue;
        }

        if (T.front()->right == nullptr) {
            T.front()->right = temp;
            T.push(temp);
        }
    }
    return head;
}

#endif //LEECODE_C_TREE_H
