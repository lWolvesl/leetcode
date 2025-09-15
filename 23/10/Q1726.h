//
// Created by 李洋 on 2023/10/19.
//

#ifndef LEECODE_C_Q1726_H
#define LEECODE_C_Q1726_H

#include <vector>
#include <map>
#include <../../dataStruct/Combination.h>

using namespace std;

int tupleSameProduct(vector<int> &nums) {
    int count = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            m[nums[i] * nums[j]] = m[nums[i] * nums[j]] + 1;
        }
    }
    for (auto &pair: m) {
        if (pair.second > 1) {
            count += pair.second * (pair.second - 1) * 4;
        }
    }
    return count;
}

int tupleSameProduct2(vector<int> &nums) {
    int count = 0;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            result.push_back(nums[i] * nums[j]);
        }
    }
    sort(result.begin(), result.end());
    int temp = 0;
    int num = nums[0];
    for (int i = 1; i < result.size(); ++i) {
        if (result[i] == num) {
            count += (temp++) * 8;
        } else {
            num = result[i];
            temp = 0;
        }
        if (result[i] == result[i - 1]) {
            count += 8;
        }
    }
    return count;
}

int tupleSameProduct3(vector<int> &nums) {
    int count = 0;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            result.push_back(nums[i] * nums[j]);
        }
    }
    sort(result.begin(), result.end());
    int temp = 1;
    int num = nums[0];
    for (int i = 1; i < result.size(); ++i) {
        if (result[i] == num) {
            temp++;
        } else {
            count += temp * (temp - 1) * 4;
            num = result[i];
            temp = 1;
        }
    }
    return count;
}
#endif //LEECODE_C_Q1726_H
