#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> v;
            dfs(v, "", n, n);
            return v;
        }
        void dfs(vector<string> &v, string s, int lc, int rc){
            if(lc == 0 && rc == 0){
                v.push_back(s);
                return;
            }
            if(lc != 0) dfs(v, s + '(', lc - 1, rc);
            if(rc != 0 && rc - 1 >= lc){
                dfs(v, s + ')', lc, rc - 1);
            }
        }
    };
