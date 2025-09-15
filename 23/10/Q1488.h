//
// Created by 李洋 on 2023/10/13.
//

#ifndef LEECODE_C_Q1488_H
#define LEECODE_C_Q1488_H

#include <vector>
#include <map>

using namespace std;

class Q1488 {
public:
    vector<int> avoidFlood(vector<int> &rains) {
        map<int, int> m;
        vector<int> ret;
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                for (int j = i + 1; j < rains.size(); ++j) {
                    if (j > 0) {
                        if (m[rains[j]] == 1) {
                            m.erase(rains[j]);
                            ret.push_back(rains[j]);
                            break;
                        }
                    }
                    if (j == rains.size() - 1) {
                        ret.push_back(1);
                    }
                }
                continue;
            }
            if (m[rains[i]]) {
                return vector<int>();
            }
            m[rains[i]] = 1;
            ret.push_back(-1);
        }
        return ret;
    }
};

#endif //LEECODE_C_Q1488_H
