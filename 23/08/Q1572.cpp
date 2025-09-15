#include <vector>

using namespace std;

class Q1572 {
public:
    int diagonalSum_1(vector<vector<int>> &mat) {
        int sum = 0;
        for (int i = 0; i < mat.size(); ++i) {
            sum += mat[i][i] + mat[i][mat.size() - i - 1];
        }
        if ((mat.size() & 1) == 1) {
            sum -= mat[mat.size() / 2][mat.size() / 2];
        }
        return sum;
    }
};