//
// Created by 李洋 on 2023/8/6.
//

#ifndef LEECODE_C_LISTS_H
#define LEECODE_C_LISTS_H
#pragma once

#include <iostream>
#include <random>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void list() {
        ListNode *temp = this;
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    int *array() {
        int *array = new int[len()];
        ListNode *temp = this;
        int index = 0;
        while (temp) {
            array[index++] = temp->val;
            temp = temp->next;
        }
        return array;
    }

    int len() {
        int length = 0;
        ListNode *temp = this;
        while (temp) {
            temp = temp->next;
            length++;
        }
        return length;
    }
};

ListNode *createRandomList(int len) {
    ListNode *p = nullptr;
    std::random_device rd;
    std::uniform_int_distribution<int> dis(1, 100);
    std::mt19937 gen(rd());
    while (--len >= 0) {
        auto *temp = new ListNode(dis(gen), p);
        p = temp;
    }
    return p;
}


#endif //LEECODE_C_LISTS_H
