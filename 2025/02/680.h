#include <string.h>
#include <stdbool.h>

bool checkPalindrome(const char* s, int low, int high) {
    for (int i = low, j = high; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

bool validPalindrome(char* s) {
    int low = 0, high = strlen(s) - 1;
    while (low < high) {
        if (s[low] == s[high]) {
            low++;
            high--;
        } else {
            return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
        }
    }
    return true;
}

void run(){
    char *s = "eccer";
    printf("%d\n",validPalindrome(s));
}