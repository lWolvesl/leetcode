#include <limits.h>

int findUnsortedSubarray(int* nums, int numsSize) {
    int n = numsSize;
    int maxn = INT_MIN, right = -1;
    int minn = INT_MAX, left = -1;
    for (int i = 0; i < n; i++) {
        if (maxn > nums[i]) {
            right = i;
        } else {
            maxn = nums[i];
        }
        if (minn < nums[n - i - 1]) {
            left = n - i - 1;
        } else {
            minn = nums[n - i - 1];
        }
    }
    return right == -1 ? 0 : right - left + 1;
}