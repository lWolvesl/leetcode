
int minChanges(int n, int k)
{
    if(n<k){
        return 1;
    }
    int count = 0;
    while (n || k == 0)
    {
        if ((n & 1) < (k & 1))
        {
            return -1;
        }
        if ((n & 1) > (k & 1))
        {
            count++;
        }
        n >>= 1;
        k >>= 1;
    }
    return count;
}

int minChanges1(int n, int k) {
        return (n & k) == k ? __builtin_popcount(n ^ k) : -1;
}