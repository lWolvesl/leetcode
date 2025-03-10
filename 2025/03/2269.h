#include <math.h>
#include <limits.h>

int count_digits_log(int num) {
    if (num == 0) return 1;
    long long temp = num; // 处理INT_MIN的溢出
    if (temp < 0) temp = -temp;
    return (int)log10(temp) + 1;
}

int divisorSubstrings(int num, int k) {
    int count = 0;
    long n = labs(num); // 处理负数情况
    int len = count_digits_log(n);
    long divisor = pow(10, len - k); // 预计算除数
    
    for (int i = 0; i <= len - k; i++) {
        long sub = (n / divisor) % (long)pow(10, k); // 正确提取k位子数
        divisor /= 10;
        
        if (sub != 0 && num % sub == 0) { // 排除0的情况
            count++;
        }
    }
    return count;
}