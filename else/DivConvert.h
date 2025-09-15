//
// Created by 李洋 on 2023/10/2.
//

#ifndef LEECODE_C_DIVCONVERT_H
#define LEECODE_C_DIVCONVERT_H

#include <stack>
#include <string>

using namespace std;

string decimalToBinaryUsingEuclidean(int target) {
    stack<int> s;
    string result = "";
    while (target) {
        s.push(target % 2);
        target /= 2;
    }
    while (!s.empty()) {
        result.append(to_string(s.top()));
        s.pop();
    }
    return result;
}

// test : cout << decimalToBinaryUsingEuclidean(555) << endl;

#endif //LEECODE_C_DIVCONVERT_H
