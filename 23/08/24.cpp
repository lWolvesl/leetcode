#pragma once
#include "lists.h"

class Q24 {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p1;
        ListNode *p2;
        p1 = head;
        p2 = head->next;

        while (!p2){
            p1->next = p2->next;
            p2->next = p1;

            if(!p1->next){
                return head;
            }

            p1 = p1->next;
            p2 = p1->next;
        }
        return head;
    }
};