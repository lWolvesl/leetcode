//
// Created by 李洋 on 2023/9/6.
//

#ifndef LEECODE_C_Q1123_H
#define LEECODE_C_Q1123_H
#pragma once

#include "../../dataStruct/Tree/TreeStack.h"

std::pair<TreeNode *, int> f(TreeNode *root) {
    if (!root) {
        return {root, 0};
    }

    auto left = f(root->left);
    auto right = f(root->right);

    if (left.second > right.second) {
        return {left.first, left.second + 1};
    }
    if (left.second < right.second) {
        return {right.first, right.second + 1};
    }
    return {root, left.second + 1};

}

struct TreeNode *lcaDeepestLeaves(struct TreeNode *root) {
    return f(root).first;
}


#endif //LEECODE_C_Q1123_H
