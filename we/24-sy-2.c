#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};


// 带头节点的单链表插入排序
void insertSort(struct ListNode *head){
    struct ListNode *p = head->next;
    struct ListNode *q;
    
    if (p == NULL || p->next == NULL) return; // 空链表或单节点无需排序

    while(p->next) {
        q = head;
        while (q->next != p->next) {
            if(q->next->val < p->next->val) {
                q = q->next;
            } else {
                // 插入操作
                struct ListNode *temp = p->next;
                p->next = temp->next;
                temp->next = q->next;
                q->next = temp;
                break; // 插入完成后立即跳出
            }
        }
        // 只有没发生插入时才移动p指针
        if (q->next == p->next) { 
            p = p->next;
        }
    }
}
