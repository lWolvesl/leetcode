#include <stdlib.h>

typedef struct ListNode
{
    int val;
    ListNode *next;
} ListNode;


// 若使用了带头节点的链表，则无需判断head是否为空
ListNode *createListNode(int val)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(ListNode *head)
{
    ListNode *temp = head;
    while(temp){
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// 添加节点
ListNode *addNode(ListNode *head,int val)
{
    if(head == NULL){
        head = createListNode(val);
        return head;
    }
    ListNode *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    temp->next = node;
    return head;
}

int Locate(ListNode *head,int val){
    if(head == NULL){
        return -1;
    }
    ListNode *temp = head;
    int index = 0;
    while(temp){
        if(temp->val==val){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

// 删除节点
ListNode *deleteNode(ListNode *head,int val){
    if(head == NULL){
        return NULL;
    }

    ListNode *temp1 = head;
    if(temp1->val == val){
        head = temp1->next;
        free(temp1);
        return head;
    }

    ListNode *temp2 = head->next;
    while (temp2)
    {
        if(temp2->val == val){
            temp1->next = temp2->next;
            free(temp2);
            return head;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return head;
}

ListNode *insertNode(ListNode *head,int val,int index){
    if(head == NULL){
        head = createListNode(val);
        return head;
    }

    ListNode *temp = head;
    int i = 0;
    while(i < index-1 && temp){
        temp = temp->next;
        i++;
    }

    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = temp->next;
    temp->next = node;
    return head;
}
