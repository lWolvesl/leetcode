#include <algorithm>
#include <immintrin.h>
#include <numeric>
#include <vector>

class Solution {
public:
  int maximumSum(std::vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    std::vector<int> b[3];
    for (auto num : nums)
      b[num % 3].push_back(num);
    for (int i = 0; i < 3; i++) {
      std::sort(b[i].begin(), b[i].end(), [](int a, int b) { return a > b; });
      if (b[i].size() >= 3) {
        ans = std::max(std::reduce(b[i].begin(), b[i].begin() + 3), ans);
      }
    }
    if (b[0].size() && b[1].size() && b[2].size()) {
      ans = std::max(ans, b[0][0] + b[1][0] + b[2][0]);
    }
    return ans;
  }
};