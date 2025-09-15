#ifndef LEECODE_C_Q1346_H
#define LEECODE_C_Q1346_H
#include <map>
using namespace std;

class Q1346 {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i:arr){
            m[i] = 1;
        }

        for(auto [key,value]:m){
            if (m[key*2] == 1)
            {
                return true;
            }
            
        }
        return false;
    }
};

#endif LEECODE_C_Q1346_H