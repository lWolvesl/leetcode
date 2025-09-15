#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef enum { INT_TYPE, FLOAT_TYPE, DOUBLE_TYPE } ElementType;

typedef struct {
    ElementType type;
    union {
        int intValue;
        float floatValue;
        double doubleValue;
    } data;
} Item;

typedef struct {
    Item items[MAX_SIZE];
    int size;
} PriorityQueue;

PriorityQueue createPriorityQueue() {
    PriorityQueue pq;
    pq.size = 0;
    return pq;
}

bool isLess(Item item1, Item item2) {
    if (item1.type != item2.type) {
        fprintf(stderr, "错误：无法比较不同类型的元素。\n");
        return false;
    }
    switch (item1.type) {
        case INT_TYPE:
            return item1.data.intValue < item2.data.intValue;
        case FLOAT_TYPE:
            return item1.data.floatValue < item2.data.floatValue;
        case DOUBLE_TYPE:
            return item1.data.doubleValue < item2.data.doubleValue;
        default:
            fprintf(stderr, "错误：未知的元素类型。\n");
            return false;
    }
}

void swap(Item* item1, Item* item2) {
    Item temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}

void push(PriorityQueue* pq, Item newItem) {
    if (pq->size >= MAX_SIZE) {
        fprintf(stderr, "错误：优先队列已满，无法插入元素。\n");
        return;
    }

    int childIndex = pq->size;
    pq->items[childIndex] = newItem;
    pq->size++;

    int parentIndex = (childIndex - 1) / 2;
    while (childIndex > 0 && isLess(pq->items[childIndex], pq->items[parentIndex])) {
        swap(&pq->items[childIndex], &pq->items[parentIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

Item pop(PriorityQueue* pq) {
    if (pq->size <= 0) {
        fprintf(stderr, "错误：优先队列为空，无法弹出元素。\n");
        Item emptyItem;
        emptyItem.type = INT_TYPE; // 返回一个空元素
        emptyItem.data.intValue = 0;
        return emptyItem;
    }

    Item minItem = pq->items[0];
    pq->size--;

    pq->items[0] = pq->items[pq->size];
    int parentIndex = 0;
    while (true) {
        int leftChildIndex = parentIndex * 2 + 1;
        int rightChildIndex = parentIndex * 2 + 2;
        int smallestIndex = parentIndex;

        if (leftChildIndex < pq->size && isLess(pq->items[leftChildIndex], pq->items[smallestIndex])) {
            smallestIndex = leftChildIndex;
        }
        if (rightChildIndex < pq->size && isLess(pq->items[rightChildIndex], pq->items[smallestIndex])) {
            smallestIndex = rightChildIndex;
        }

        if (smallestIndex == parentIndex) {
            break; // 已经是最小堆，无需继续下沉
        }

        swap(&pq->items[parentIndex], &pq->items[smallestIndex]);
        parentIndex = smallestIndex;
    }

    return minItem;
}

int main() {
    PriorityQueue pq = createPriorityQueue();

    // 向优先队列中插入一些元素
    Item item1, item2, item3;
    item1.type = INT_TYPE;
    item1.data.intValue = 5;
    item2.type = INT_TYPE;
    item2.data.intValue = 2;
    item3.type = INT_TYPE;
    item3.data.intValue = 10;

    push(&pq, item1);
    push(&pq, item2);
    push(&pq, item3);

    // 从优先队列中弹出元素
    Item minItem = pop(&pq);
    printf("弹出的最小元素为：%d\n", minItem.data.intValue);

    return 0;
}
