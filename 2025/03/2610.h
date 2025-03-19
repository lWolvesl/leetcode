#include <stdlib.h>
#include <strings.h>
// 简易哈希表

int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int* hash = (int*)malloc(sizeof(int)*(numsSize+1));
    if(hash == NULL){
        return NULL;
    }
    memset(hash,0,sizeof(int)*(numsSize+1));
    int max = 0;
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++;
        max = max > hash[nums[i]] ? max : hash[nums[i]];
    }

    int *temp = (int*)malloc(sizeof(int)*(numsSize+1));
    if(temp == NULL){
        return NULL;
    }
    int index = 0;
    int **ans = (int**)malloc(sizeof(int*)*max);
    if(ans == NULL){
        return NULL;
    }
    *returnSize = max;
    *returnColumnSizes = (int*)malloc(sizeof(int)*max);
    for (int i = 0; i < max; i++){
        ans[i] = (int*)malloc(sizeof(int)*(numsSize+1));
        if(ans[i] == NULL){
            return NULL;
        }
        memset(temp,0,sizeof(int)*(numsSize+1));
        index = 0;
        for (int j = 0; j < numsSize+1; j++){
            if(hash[j] == 0 || temp[j] > 0){
                continue;
            }
            ans[i][index++] = j;
            hash[j]--;
            temp[j]++;
        }
        (*returnColumnSizes)[i] = index;
    }
    return ans;
}