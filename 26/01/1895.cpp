#include <vector>

class Solution {
public:
    int largestMagicSquare(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> preM(m,std::vector<int>(n,0)),preN(m,std::vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for(int j = 0;j < n;j++){
                preM[m][n] += grid[m][n];
            }
        }
    }
};