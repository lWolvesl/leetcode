#include <vector>
using namespace std;

void odd_even(vector<int> &array)
{
    int left = 0;
    int right = array.size() - 1;
    while (left < right)
    {
        while (left < right && array[right] % 2 == 0)
        {
            right--;
        }
        while (left < right && array[left] % 2 == 1)
        {
            left++;
        }
        swap(array[left], array[right]);
    }
}

#include "../structs/Tree.h"

void insertSearchTree(TreeNode *root, int value)
{
    TreeNode *dist = new TreeNode();
    dist->val = value;
    if (!root)
    {
        root = dist;
    }
    TreeNode *temp = root;
    while (temp)
    {
        if (temp->val > value)
        {
            if (temp->left)
            {
                temp = temp->left;
                continue;
            }
            temp->left = dist;
            break;
        }
        if (temp->val < value)
        {
            if (temp->right)
            {
                temp = temp->right;
                continue;
            }
            temp->left = dist;
            break;
        }
        if (temp->val == value)
        {
            break;
        }
    }
}