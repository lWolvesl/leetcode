//
// Created by 李洋 on 2023/12/17.
//

#ifndef LEECODE_C_TEST1_H
#define LEECODE_C_TEST1_H

#include "stdlib.h"

typedef struct LinkNode {
    char value;
    struct LinkNode *next;
} *Node;

struct p {
    int length;
    Node head;
};

p create(Node l1) {
    if (!l1) {
        return p{0, nullptr};   //NULL
    }

    Node temp = (Node) malloc(sizeof(LinkNode));
    temp->value = l1->value;
    l1 = l1->next;

    Node head = temp;

    int length = 1;
    while (l1) {
        temp = (Node) malloc(sizeof(LinkNode));
        temp->value = l1->value;
        temp->next = head;
        l1 = l1->next;
        head = temp;
        length++;
    }
    return p{length, head};
}

Node test(Node l1, Node l2) {
    p p1 = create(l1);
    p p2 = create(l2);

    Node n1 = p1.head;
    Node n2 = p2.head;

    int index = 0;
    while (n1->value == n2->value) {
        n1 = n1->next;
        n2 = n2->next;
        index++;
    }

    Node ps = l1;
    int length = p1.length - index;
    while (length--) {
        ps = ps->next;
    }

    return ps;
}

#endif //LEECODE_C_TEST1_H
