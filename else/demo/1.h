//
// Created by 李洋 on 2024/1/8.
//

#ifndef LEECODE_C_1_H
#define LEECODE_C_1_H

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void test1() {
    //方式一
    int a;
    cout << "输入长度:";
    cin >> a;
    int *p = (int *) malloc(a * sizeof(int)); //c写法在运行中分配空间创建指定长度数组
    p[a - 1] = 1;
    cout << p[a-1] << endl;

    //方式2 推荐
    vector<int> b; //c++ 向量，可以看作是动态数组，自动扩充容量
    vector<vector<int>> c; //二维动态数组
    b.push_back(1);
    b.push_back(2);
    b.size(); //获取当前长度
}

#endif //LEECODE_C_1_H
