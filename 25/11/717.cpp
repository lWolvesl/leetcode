#include <vector>

bool isOneBitCharacter(std::vector<int> &bits) {
  bool tag = true;
  int n = bits.size();
  for (int i = 0; i < n; i++) {
    if (tag && bits[i] == 1) {
      tag = false;
      continue;
    }
    if (tag && bits[i] == 0) {
      continue;
    }
    if (i != n - 1) {
      tag = true;
    }
  }
  return tag;
}