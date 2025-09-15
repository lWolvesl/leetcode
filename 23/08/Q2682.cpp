//
// Created by 李洋 on 2023/8/16.
//
#include "vector"
using namespace std;
class Q2682 {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visit(n, false);
        for (int i = k, j = 0; !visit[j]; i += k) {
            visit[j] = true;
            j = (j + i) % n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};