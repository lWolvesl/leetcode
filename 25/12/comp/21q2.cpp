#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  long long minCost(std::string s, std::vector<int> &cost) {
    std::unordered_map<char, long long> m;
    int n = cost.size();
    long long sum = 0, ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      m[s[i]] += cost[i];
      sum += cost[i];
    }
    for (auto [k, v] : m) {
      ans = std::min(ans, sum - v);
    }
    return ans;
  }
};