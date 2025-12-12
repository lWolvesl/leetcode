#include <vector>

class Solution {
public:
    int countCoveredBuildings(int n, std::vector<std::vector<int>>& buildings) {
        std::vector<int> maxX(n + 1);
        std::vector<int> minX(n + 1, n + 1);
        std::vector<int> maxY(n + 1);
        std::vector<int> minY(n + 1, n + 1);

        for (auto &p : buildings) {
            int x = p[0], y = p[1];
            maxX[y] = std::max(maxX[y], x);
            minX[y] = std::min(minX[y], x);
            maxY[x] = std::max(maxY[x], y);
            minY[x] = std::min(minY[x], y);
        }
        
        int res = 0;
        for (auto &p : buildings) {
            int x = p[0], y = p[1];
            if (x > minX[y] && x < maxX[y] && y > minY[x] && y < maxY[x]) {
                res++;
            }
        }

        return res;
    }
};