#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ListNode {
    char *val;
    int count;
    struct ListNode *next;
};

struct ListNode *initNode(char *val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 返回值带头节点
struct ListNode *process(const char *fileName){
    struct ListNode *head = initNode("");

    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("open file failed\n");
        return head;
    }

    char buffer[1024];
    char *words[1000];
    int wordCount = 0;

    while (fscanf(fp, "%s", buffer) != EOF && wordCount < 1000) {
        words[wordCount] = strdup(buffer);  // 使用 strdup 复制字符串
        wordCount++;
    }

    int tag = 0; // 0 表示还没有处理，1 表示已经处理
    
    for (int i = 0; i < wordCount; i++) {
        struct ListNode *p = head;
        tag = 0;
        while(p->next != NULL) {
            if(strcmp(p->next->val, words[i]) == 0){
                p->next->count++;
                tag = 1;
                break;
            }
            p = p->next;
        }
        if(tag == 0) {
            struct ListNode *node = initNode(words[i]);
            node->count = 1;
            p->next = node;
        }
    }

    fclose(fp);
    
    return head;
}