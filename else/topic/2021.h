#include <vector>
#include <stack>

using namespace std;

int test1(vector<int> array)
{
    if (array.empty())
    {
        return INT_MIN;
    }
    stack<int> S;
    int norm = array[0];
    int m = INT_MIN;
    S.push(array[0]);
    for (int i = 1; i < array.size(); i++)
    {
        m = max(m, norm - array[i]);
        while (!S.empty() && array[i] > S.top())
        {
            S.pop();
        }
        if (S.empty())
        {
            norm = array[i];
        }
        S.push(array[i]);
    }
    return m;
}

#include "../structs/Tree.h"
int test2(TreeNode *root){
    //先镜像，再按需遍历
}