#include <stdlib.h>
#include <string.h>
#include <limits.h>

int find(char **species,int size,char *str){
    for(int i = 0; i<size;i++){
        if (strcmp(species[i], str) == 0)
        {
            return i;   
        }
    }
    return -1;
}


// 传入咒语字符串数组（二维数组）eg. {{"猫"，"alal","鱼"},{x,x,x}} 代表猫变老鼠咒语为"alal"

char *find_best_animal(char ***curses, int cursesSize)
{
    char **species = (char **)malloc(sizeof(char *) * 2 * cursesSize);
    if(species == NULL){
        return "error,fail to malloc memory";
    }
    int size = 0;
    for(int i = 0;i<cursesSize;i++){    //统计个数并建立映射关系，时间复杂度为o(n^2),使用哈希表(c语言哈希表篇幅过长)可以降到o(1)
        for(int j=0;j<3;j++){
            if(j==1){
                continue;
            }
            if(find(species,size,curses[i][j])==-1){
                species[size++]=curses[i][j];
            }
        }
    }

    int **matrix = (int**)malloc(sizeof(int*) * size);  // 准备空间以便后续弗洛伊德操作
    if(matrix == NULL){
        return "error,fail to malloc memory";
    }
    for(int i = 0; i < size; i++){
        matrix[i] = (int*)malloc(sizeof(int) * size);
        if(matrix[i] == NULL){
            // 释放之前分配的内存
            for(int j = 0; j < i; j++){
                free(matrix[j]);
            }
            free(matrix);
            return "error,fail to malloc memory";
        }
        // 初始化数组元素为-1
        memset(matrix[i], -1, sizeof(int) * size);
    }

    for(int i=0;i<cursesSize;i++){
        int x = find(species,size,curses[i][0]);
        int y = find(species,size,curses[i][2]);
        int len = strlen(curses[i][1]);
        
        // 保留最短路径
        if(matrix[x][y] == -1 || len < matrix[x][y]) {
            matrix[x][y] = len;
        }
    }

    for(int i = 0;i<size;i++){              // 实现弗洛伊德操作
        for(int j = 0;j<size;j++){
            if(j==i || matrix[j][i] == -1){
                continue;
            }
            for(int k = 0;k<size;k++){
                if(k==i || matrix[i][k] == -1 || j==k){
                    continue;
                }

                // 更新最短路径
                if(matrix[j][k] == -1 || matrix[j][i] + matrix[i][k] < matrix[j][k]) {
                    matrix[j][k] = matrix[j][i] + matrix[i][k];
                }
            }
        }
    }

    int res = -1;
    int min = INT_MAX;
    for(int i = 0;i<size;i++){
        int cost = 0;
        int valid = 1;
        for(int j = 0;j<size;j++){
            if(i != j){
                if(matrix[i][j] == -1){
                    valid = 0;
                    break;
                }
                cost += matrix[i][j];
            }
        }
        if(valid && min > cost){
            min = cost;
            res = i;
        }
    }
    
    // 释放内存
    for(int i = 0; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);

    char *animal = res != -1 ? species[res] : NULL;

    free(species);
    
    return animal;
}