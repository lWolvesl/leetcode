//
// Created by 李洋 on 2023/10/22.
//

#ifndef LEECODE_C_T368_H
#define LEECODE_C_T368_H

#include <vector>

using namespace std;

int minimumSum(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    for (int i = 0; i < right; ++i) {
            if (nums[left] >= nums[i]) {
                left = i;
            }
    }
    for (int i = right; i > left; --i) {
            if (nums[right] >= nums[i]) {
                right = i;
            }
    }
    if (right - left == 1) {
        return -1;
    }
    int max = left + 1;
    for (int i = left + 1; i < right; ++i) {
        if (nums[max] >= nums[i]) {
            max = i;
        }
    }
    return nums[left] + nums[right] + nums[max];
}

void runT368() {
    vector<int> arr; // [5,4,8,7,10,2]  / [6,5,4,3,4,5]
   /* arr.push_back(5);
    arr.push_back(4);
    arr.push_back(8);
    arr.push_back(7);
    arr.push_back(10);
    arr.push_back(2);*/
//    arr.push_back(6);
//    arr.push_back(5);
//    arr.push_back(4);
//    arr.push_back(3);
//    arr.push_back(4);
//    arr.push_back(5);
    arr.push_back(50);
    arr.push_back(50);
    arr.push_back(50);
    auto result = minimumSum(arr);
}

#endif //LEECODE_C_T368_H
