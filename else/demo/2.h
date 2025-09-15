//
// Created by 李洋 on 2024/1/11.
//

#ifndef LEECODE_C_2_H
#define LEECODE_C_2_H

#include <iostream>

using namespace std;

void test1(int *p, int index) {
    cout << p[index];
}

void run() {
    int arr[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    test1(arr, 2);
}

#endif //LEECODE_C_2_H
