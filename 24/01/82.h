//
// Created by 李洋 on 2024/1/15.
//

#ifndef LEECODE_C_82_H
#define LEECODE_C_82_H

// 本题与83题中要求删除重复多余的节点不同，要求只要重复就删除掉所有重复的节点，关机在于链表头的处理
// 这里采用的是创建一个新的头节点，然后对后续节点进行继续处理，一次遍历即可

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
    if (!head) {
        return head;
    }

    ListNode* dummy = new ListNode(0, head);

    ListNode* cur = dummy;
    while (cur->next && cur->next->next) {
        if (cur->next->val == cur->next->next->val) {
            int x = cur->next->val;
            while (cur->next && cur->next->val == x) {
                cur->next = cur->next->next;
            }
        }
        else {
            cur = cur->next;
        }
    }

    return dummy->next;
}

#endif //LEECODE_C_82_H
