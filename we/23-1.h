#include <string.h>

int countSubstring(char *A,char *B){
    int count = 0;
    char *p = A;
    while(*p != '\0'){
        p = strstr(p,B);
        if(p != NULL){
            count++;
            p += strlen(B);
        }else{
            break;
        }
    }
    return count;
}