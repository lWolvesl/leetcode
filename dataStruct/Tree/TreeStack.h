//
// Created by 李洋 on 2023/9/6.
//

#ifndef LEECODE_C_TREESTACK_H
#define LEECODE_C_TREESTACK_H
#pragma once

#include <iostream>
#include <vector>
#include "./Tree.h"

class TreeStack {
private:
    std::vector<TreeNode *> data;

public:
    // 入栈操作
    void push(TreeNode *value) {
        data.push_back(value);
    }

    // 出栈操作
    TreeNode *pop() {
        if (!isEmpty()) {
            TreeNode *topValue = data.back();
            data.pop_back();
            return topValue;
        } else {
            std::cerr << "Error: Stack is empty." << std::endl;
            return nullptr; // 可以根据需要返回其他值或抛出异常
        }
    }

    // 获取栈顶元素
    TreeNode *top() const {
        if (!isEmpty()) {
            return data.back();
        } else {
            std::cerr << "Error: Stack is empty." << std::endl;
            return nullptr; // 可以根据需要返回其他值或抛出异常
        }
    }

    // 检查栈是否为空
    bool isEmpty() const {
        return data.empty();
    }

    // 获取栈的大小
    size_t size() const {
        return data.size();
    }
};

#endif //LEECODE_C_TREESTACK_H
