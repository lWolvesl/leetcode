//
// Created by 李洋 on 2024/1/3.
//

#ifndef LEECODE_C_2497_H
#define LEECODE_C_2497_H

#include "../../dataStruct/LinkedList/lists.h"
#include <stack>

using namespace std;

//单调栈
ListNode *removeNodes(ListNode *head) {
    stack<ListNode *> S;
    S.push(head);
    ListNode *temp = head->next;
    while (temp) {
        while (!S.empty() && temp->val > S.top()->val) {
            S.pop();
        }
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    S.pop();
    while (!S.empty()) {
        S.top()->next = temp;
        temp = S.top();
        S.pop();
    }
    return temp;
}

#endif //LEECODE_C_2497_H
