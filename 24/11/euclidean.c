#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

struct stacks{
    int data[MaxSize];
    int top;
};

char *euclidean(int n, int r){
    struct stacks s;
    s.top = -1;

    // 检查基数范围
    if (r < 2 || r > 36) {
        return NULL; // 无效的基数
    }

    // 处理 n 为 0 的情况
    if (n == 0) {
        char *result = (char *)malloc(2);
        if (!result) return NULL; // 内存分配失败
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // 处理负数
    int isNegative = 0;
    if (n < 0) {
        isNegative = 1;
        n = -n;
    }

    while(n > 0){
        if (s.top + 1 >= MaxSize) {
            return NULL; // 栈溢出
        }
        s.data[++s.top] = n % r;
        n = n / r;
    }

    // 计算需要的内存大小：字符数 + 可能的负号 + 终止符
    int size = s.top + 1 + isNegative + 1;
    char *result = (char *)malloc(sizeof(char) * size);
    if (!result) {
        return NULL; // 内存分配失败
    }

    int i = 0;
    if (isNegative) {
        result[i++] = '-';
    }

    while(s.top != -1){
        int value = s.data[s.top--];
        if (value < 10) {
            result[i++] = '0' + value;
        } else {
            result[i++] = 'A' + (value - 10);
        }
    }
    result[i] = '\0';
    return result;
}