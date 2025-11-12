#include <algorithm>
#include <vector>
#include <numeric>

int minOperations(std::vector<int>& nums) {
    int gcd_min = 0; 
    int n = nums.size();
    int count = 0;
    for (auto num : nums) {
        gcd_min = std::gcd(gcd_min, num);
        count += num == 1;
    }
    if (gcd_min > 1) {
        return -1;
    }
    if (count) return n - count;

    int min_size = n;
    for(int i = 0;i<n;i++){
        int g = 0;
        for (int j = i; j < n; j++) {
            g = std::gcd(g,nums[j]);
            if(g == 1){
                min_size = std::min(min_size,j-i);
                break;
            }
        }
    }
    return min_size + n - 1;
}

int main(){

}