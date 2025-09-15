//
// Created by 李洋 on 2023/10/12.
//

#ifndef LEECODE_C_TRAVERSE_H
#define LEECODE_C_TRAVERSE_H
using namespace std;

#include "structs/Tree.h"
#include <queue>
#include <stack>

queue<TreeNode *> Q;

// 递归写法 - int型
// 先序遍历 preorder traversal
void preorder_recursion_help(TreeNode *head) {
    if (head != nullptr) {
        Q.push(head);
        preorder_recursion_help(head->left);
        preorder_recursion_help(head->right);
    }
}

queue<TreeNode *> preorder_recursion(TreeNode *head) {
    preorder_recursion_help(head);
    return Q;
};

// 中序遍历 inorder traversal
void inorder_recursion_help(TreeNode *head) {
    if (head != nullptr) {
        inorder_recursion_help(head->left);
        Q.push(head);
        inorder_recursion_help(head->right);
    }
}

queue<TreeNode *> inorder_recursion(TreeNode *head) {
    inorder_recursion_help(head);
    return Q;
};

// 后序遍历 postorder traversal
void postorder_recursion_help(TreeNode *head) {
    if (head != nullptr) {
        postorder_recursion_help(head->left);
        postorder_recursion_help(head->right);
        Q.push(head);
    }
}

queue<TreeNode *> postorder_recursion(TreeNode *head) {
    postorder_recursion_help(head);
    return Q;
};

// 非递归写法
// 先序遍历 preorder traversal
queue<TreeNode *> preorder(TreeNode *head) {
    if (!head) {
        return Q;
    }

    auto temp = head;

    stack < TreeNode * > S;

    S.push(temp);

    TreeNode *t;

    while (!S.empty()) {
        t = S.top();
        S.pop();
        Q.push(t);
        if (t->right)
            S.push(t->right);
        if (t->left)
            S.push(t->left);
    }
    return Q;
}

// 中序遍历 inorder traversal
queue<TreeNode *> inorder(TreeNode *head) {
    auto temp = head;
    stack < TreeNode * > S;

    while (temp != nullptr || !S.empty()) {
        if (temp) {
            S.push(temp);
            temp = temp->left;
            continue;
        }
        temp = S.top();
        Q.push(temp);
        S.pop();
        temp = temp->right;
    }
    return Q;
}

// 后序遍历 postorder traversal
queue<TreeNode *> postorder(TreeNode *head) {
    auto temp = head;
    stack <pair<TreeNode *, bool>> S;

    while (temp != nullptr || !S.empty()) {
        if (temp) {
            S.emplace(temp, false);
            temp = temp->left;
            continue;
        }
        temp = S.top().first;

        if (temp->right == nullptr || S.top().second) {
            Q.push(temp);
            S.pop();
            temp = nullptr;
            continue;
        }
        S.top().second = true;
        temp = temp->right;
    }
    return Q;
}

void test1() {
    auto TreeNode = createRandomTree(10);
    auto Q = postorder(TreeNode);
    while (!Q.empty()) {
        cout << Q.front()->val << " ";
        Q.pop();
    }
}

#endif //LEECODE_C_TRAVERSE_H
