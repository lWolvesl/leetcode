#include <algorithm>
#include <vector>

class Solution {
public:
  long long maximumHappinessSum(std::vector<int> &happiness, int k) {
    long long ans = 0;
    std::sort(happiness.begin(), happiness.end(),
              [](int a, int b) { return a > b; });
    for (int i = 0; i < k && i < happiness.size(); i++) {
      if (happiness[i] < i) {
        break;
      }
      ans += happiness[i] - i;
    }
    return ans;
  }
};