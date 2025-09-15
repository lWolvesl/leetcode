//
// Created by 李洋 on 2023/10/18.
//

#ifndef LEECODE_C_TEST_H_P
#define LEECODE_C_TEST_H_P

#include <queue>
#include <iostream>

using namespace std;

void testPQ() {
    priority_queue<int, deque<int>, less<>> maxHeap;
    maxHeap.push(1);
    maxHeap.push(10);
    maxHeap.push(3);
    maxHeap.push(3);
    maxHeap.push(3);
    cout << maxHeap.top() << endl;
    maxHeap.pop();
    maxHeap.push(4);
    cout << maxHeap.top() << endl;
    maxHeap.pop();
    maxHeap.push(2);
    cout << maxHeap.top() << endl;
    priority_queue<int, vector<int>, greater<>> minHeap;
    minHeap.push(20);
    minHeap.push(10);
    minHeap.push(30);
    cout << minHeap.top() << endl;
}

#endif //LEECODE_C_TEST_H_P
