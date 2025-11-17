#include <vector>

bool kLengthApart(std::vector<int> &nums, int k) {
  int count = 0;
  bool start = false;

  for (int i = 0; i < nums.size(); ++i) {
    if (!start) {
      if (nums[i] == 1) {
        start = true;
      }
      continue;
    }
    if (nums[i] == 0) {
      count++;
    }
    if (nums[i] == 1) {
      if (count < k) {
        return false;
      }
      count = 0;
    }
  }

  return true;
}