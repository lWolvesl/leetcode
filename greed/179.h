#include <stdlib.h>

long cmp(int *x, int *y) {
    unsigned long sx = 10, sy = 10;
    while (sx <= *x) {
        sx *= 10;
    }
    while (sy <= *y) {
        sy *= 10;
    }
    return sx * (*y) + (*x) - sy * (*x) - (*y);
}

char *largestNumber(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] == 0) {
        char *ret = malloc(sizeof(char) * 2);
        ret[0] = '0', ret[1] = '\0';
        return "0";
    }
    char *ret = malloc(sizeof(char) * 1000);
    char *p = ret;
    for (int i = 0; i < numsSize; i++) {
        sprintf(p, "%d", nums[i]);
        p += strlen(p);
    }
    return ret;
}