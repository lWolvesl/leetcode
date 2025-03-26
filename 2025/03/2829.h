#include <unordered_map>
using namespace std;


// map 查询阶段会创建隐式创建链，会增加map.size()的大小
class Solution {
    public:
        int minimumSum(int n, int k) {
            unordered_map<int,int> m;
            int sum = 0;
            for(int i = 1;m.size()<n;i++){
                if(m[k-i] == 0){
                    m[i]++;
                    sum += i;
                }
            }
            return sum;
        }
    };