#include "tree.c"

TreeNode* findLCA(TreeNode* root, int node1, int node2) {
    if (root == NULL || root->val == node1 || root->val == node2) {
        return root;
    }

    TreeNode* left = findLCA(root->left, node1, node2);
    TreeNode* right = findLCA(root->right, node1, node2);

    if (left != NULL && right != NULL) {
        return root;
    }

    return (left != NULL) ? left : right;
}

int findLevel(TreeNode* root, int val, int level) {
    if (root == NULL) return -1;
    if (root->val == val) return level;

    int left = findLevel(root->left, val, level + 1);
    if (left != -1) return left;

    return findLevel(root->right, val, level + 1);
}

int nodeDistance(TreeNode *root, int node1, int node2) {
    TreeNode* lca = findLCA(root, node1, node2);
    if (lca == NULL) return -1;

    int d1 = findLevel(lca, node1, 0);
    int d2 = findLevel(lca, node2, 0);

    if (d1 == -1 || d2 == -1) return -1;

    return d1 + d2;
}