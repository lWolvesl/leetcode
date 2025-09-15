#include "../structs/List.h"
#include <vector>

using namespace std;

vector<vector<int>> test1(ListNode *head)
{
    vector<vector<int>> ret;

    int prev = head->value;
    int index = 0;
    ret.push_back(vector<int>(1, prev));

    ListNode *temp = head->next;

    while (!temp)
    {
        if (prev == temp->value)
        {
            index++;
        }
        else
        {
            index = 0;
        }
        if (index >= ret.size())
        {
            ret.push_back(vector<int>(1, temp->value));
        }
        if (index < ret.size())
        {
            ret[index].push_back(temp->value);
        }

        temp = temp->next;
    }

    return ret;
}

#include "../structs/Tree.h"

pair<bool, int> help(TreeNode *root)
{
    if (!root)
    {
        return {true, 0};
    }
    auto p1 = help(root->left);
    auto p2 = help(root->right);
    if (!p1.first || !p2.first)
    {
        return {false, 0};
    }
    if (abs(p1.second - p2.second) > 1)
    {
        return {false, 0};
    }

    return {true, max(p1.second, p2.second) + 1};
}

bool test2(TreeNode *root)
{
    return help(root).first;
}