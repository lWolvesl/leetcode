#include <stdlib.h>

int sumOfBeauties(int* nums, int numsSize) {
    int* state = (int*)calloc(numsSize, sizeof(int));
    int pre_max = nums[0];
    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] > pre_max) {
            state[i] = 1;
            pre_max = nums[i];
        }
    }
    int suf_min = nums[numsSize - 1];
    int res = 0;
    for (int i = numsSize - 2; i > 0; i--) {
        if (state[i] && nums[i] < suf_min) {
            res += 2;
        } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
            res += 1;
        }
        suf_min = nums[i] < suf_min ? nums[i] : suf_min;
    }
    free(state);
    return res;
}