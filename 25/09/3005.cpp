#include <vector>
#include <iostream>
#include <unordered_map>

int maxFrequencyElements(std::vector<int> &nums)
{
    std::unordered_map<int,int> m;
    std::for_each(nums.begin(),nums.end(),[&m](int x){
        m[x]++;
    });
    int max = 0;
    for_each(m.begin(),m.end(),[&max](std::pair<int,int> p){
        if (p.second > max) max = p.second;
    });
    int count = 0;
    std::for_each(m.begin(),m.end(),[&count,max](std::pair<int,int> p){
        if (p.second == max) count++;
    });

    return count;
}

int enhance_1(std::vector<int> nums) {
    std::unordered_map<int,int> m;
    int ans = 0, max = 0;
    std::for_each(nums.begin(),nums.end(),[&m,&ans,&max](int x) {
        int c = ++m[x];
        if (c > max) {
            ans = max = c;
        }else if (c == max) {
            ans += c;
        }
    });
    return ans;
}