#include "../structs/Tree.h"

using namespace std;

TreeNode *getX(TreeNode *root, int x)
{
    TreeNode *temp = root;
    while (temp)
    {
        if (temp->val > x)
        {
            if (temp->left)
            {
                temp = temp->left;
                continue;
            }
        }
        else
        {
            if (temp->right)
            {
                temp = temp->right;
                continue;
            }
        }
        return temp;
    }
}