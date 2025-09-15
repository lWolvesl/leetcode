#include <math.h>

int getN(long int a){
    int ret = 0;
    while (a)
    {
        ret++;
        a/=10;
    }
    return ret;
}

long int findMO(long int a){
    int ret = 0;
    int i = 0;
    int n = getN(a);
    while(a!=0){
        int div = pow(10,n--);
        int temp = a/div;
        a%=div;
        if(temp%2 == 1){
            ret += temp*(int)pow(10,i++);
        }
    }
    return ret;
}