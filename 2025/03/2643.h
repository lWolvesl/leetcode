#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    res[0] = 0;
    res[1] = 0;
    for(int i = 0; i < matSize; ++i) {
        int sum = 0;
        for(int j = 0; j < matColSize[i]; ++j) {
            sum += mat[i][j];
        }
        if(sum > res[1]){
            res[0] = i;
            res[1] = sum;
        }
    }
    return res;
}