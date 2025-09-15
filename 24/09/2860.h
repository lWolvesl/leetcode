#include <vector>

using namespace std;

int countWays(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int count = 0;
    for (int i = 0; i <= nums.size(); i++) {
        if (i == 0) {
            if (nums[0] != 0) {
                count++;
            }
            continue;
        }
        if (i == nums.size() && i > nums[nums.size()]) {
            count++;
            continue;
        }
        if (i > nums[i - 1] && i < nums[i])count++;
    }
    return count;
}
