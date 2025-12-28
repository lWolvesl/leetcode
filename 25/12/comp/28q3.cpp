class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k%2==0 || k%5==0) {
            return -1;
        }
        int remainder = 1;
        for (int i = 1 ;i<=k;i++) {
            if (remainder % k == 0) {
                return i;
            }
            // (a * 10 + 1) % k = ((a % k) * 10 + 1) % k
            remainder = (remainder * 10 + 1) % k;
        }
        return -1;
    }
};