#include <stdlib.h>
#include <string.h>

char *strcpys(char *dest,char *src){
    int len1 = strlen(dest);
    int len2 = strlen(src);
    char *res = (char *)malloc(sizeof(char)*(len1+len2+1));
    if(!res){
        printf("malloc failed\n");
        return NULL;
    }
    memcpy(res,dest,len1);
    memcpy(res+len1,src,len2);
    res[len1+len2] = '\0';

    free(src);
    return res;
}