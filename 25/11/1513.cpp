#include <string>


int numSub(std::string s) {
    int count = 0;
    long ans = 0;
    int mod = 1e9+7;
    int n = s.length();
    for(int i = 0;i<n;i++){
        if(s[i] == '1'){
            count++;
        }
        if(s[i] == '0' || i == n-1){
            while (count != 0) {
                ans += count--;
            }
        }
    }        
    return int(ans % mod);
}