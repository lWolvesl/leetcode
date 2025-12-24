#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        int sum = std::accumulate(apple.begin(),apple.end(),0);
        std::sort(capacity.begin(),capacity.end(),[](int a,int b){return a>b;});
        int ans = 0;
        for(auto c : capacity){
            sum -= c;
            ans++;
            if (sum <= 0) {
                break;
            }
        }
        return ans;;
    }
};