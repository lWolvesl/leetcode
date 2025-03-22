#include <stdbool.h>

bool isPalindrome(char *s){
    int len = strlen(s);
    int left = 0, right = len - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}