#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

// 方法1: 生成特定的二维vector
static vector<vector<int>> generateSpecificMatrix()
{
    return {
        {2, 3, 4, 2, 5},
        {6, 2, 3, 1, 8},
        {3, 5, 4, 6, 4},
        {4, 2, 3, 2, 3},
        {2, 1, 6, 7, 5}};
}

// 方法2: 生成随机n×n数组
vector<vector<int>> generateRandomMatrix(int n, int min_val = 1, int max_val = 10)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min_val, max_val);

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = dis(gen);
        }
    }
    return matrix;
}

// 打印矩阵的辅助函数
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << setw(3) << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int getMaxWay(std::vector<vector<int>> matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] += max(i - 1 >= 0 ? matrix[i - 1][j] : 0, j - 1 >= 0 ? matrix[i][j - 1] : 0);
        }
    }
    printMatrix(matrix);
    return matrix[n - 1][n - 1];
}

int main()
{
    auto matrix = generateSpecificMatrix();
    printMatrix(matrix);
    std::cout << getMaxWay(matrix);
    return 0;
}
