#include <vector>
#include <unordered_map>

std::vector<int> findXSum(std::vector<int> &nums, int k, int x)
{
    int l = 0;
    int r = k - 1;
    std::unordered_map<int, int> m;
    std::vector<int> ans;
    std::vector<std::pair<int,int>> temp;
    int count = 0;
    for(int i = l;i <= k - 1; ++i){
        m[nums[i]] += 1;
    }
    for(int i = 0;r < nums.size();++i){
        if(i != 0){
            
        }
        for (const auto& [key, value] : m) {
            temp.push_back(std::pair<int,int>(key,value));
        }
        std::sort(temp.begin(),temp.end(),[](std::pair<int,int> x,std::pair<int,int> y){
            return x.second > y.second;
        });
        for(int i = 0;i < x;i++){
            count += temp[i].first * temp[i].second;
        }
        ans.push_back(count);
        temp.clear();
        count = 0;
    }
    return ans;
}
