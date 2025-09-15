//
// Created by 李洋 on 2023/11/5.
//

#ifndef LEECODE_C_Q187_H
#define LEECODE_C_Q187_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ret;
    unordered_map<string, int> m;
    for(int i = 0;i+9<s.length();i++){
        m[s.substr(i,i+9)] = m[s.substr(i,i+9)] + 1;
    }
    for(auto [key,value]:m){
        if(value > 1){
            ret.push_back(key);
        }
    }
    return ret;
}

#endif //LEECODE_C_Q187_H
