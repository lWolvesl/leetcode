#include <string.h>
#include <stdlib.h>

char* destar(char *str){
    int length = strlen(str);
    char *ret = (char *)malloc(sizeof(char)*length);
    if(ret == NULL){
        return "error";
    }
    int left=0,right=length-1;
    while (str[left++]=='*');
    while (str[right--]=='*');
    strncpy(ret,str,left);
    char temp;
    int i = left;
    while (left<=right)
    {
        temp = str[left++];
        if((temp >= 'a' && temp <= 'z') || 
           (temp >= 'A' && temp <= 'Z')) {
            ret[i++] = temp;
        }else if(temp=='*'){
            continue;
        }else{
            free(ret);
            return "error";
        }
    }
    strncpy(ret+i,str+right+1,length - (right + 1));
    ret[length - (left - i)] = '\0';

    return ret;
}