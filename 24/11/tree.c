#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct StackNode
{
    TreeNode *treeNode;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

void push(Stack *stack, TreeNode *treeNode)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->treeNode = treeNode;
    newNode->next = stack->top;
    stack->top = newNode;
}

TreeNode *pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        return NULL;
    }
    StackNode *temp = stack->top;
    TreeNode *treeNode = temp->treeNode;
    stack->top = stack->top->next;
    free(temp);
    return treeNode;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    Stack stack = {NULL};
    TreeNode *p = root;
    while (p != NULL || !isEmpty(&stack))
    {
        while (p != NULL)
        {
            printf("%d ", p->val);
            push(&stack, p);
            p = p->left;
        }
        p = pop(&stack);
        p = p->right;
    }
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    Stack stack = {NULL};
    TreeNode *p = root;
    while (p != NULL || !isEmpty(&stack))
    {
        while (p != NULL)
        {
            push(&stack, p);
            p = p->left;
        }
        p = pop(&stack);
        printf("%d ", p->val);
        p = p->right;
    }
}

void postorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    Stack stack = {NULL};
    TreeNode *p = root;
    TreeNode *pre = NULL;
    do
    {
        while (p != NULL)
        {
            push(&stack, p);
            p = p->left;
        }
        p = pop(&stack);
        if (p->right == NULL || p->right == pre)
        {
            printf("%d ", p->val);
            pre = p;
            p = NULL;
        }
        else
        {
            push(&stack, p);
            p = p->right;
        }
    } while (!isEmpty(&stack));
}

void Postorderd(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorderd(root->left);
    Postorderd(root->right);
    printf("%d ", root->val);
}


TreeNode* createTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* generateCompleteBinaryTree(int nodeCount) {
    if (nodeCount <= 0) {
        return NULL;
    }

    srand(time(NULL));
    TreeNode** nodes = (TreeNode**)malloc(nodeCount * sizeof(TreeNode*));
    for (int i = 0; i < nodeCount; i++) {
        nodes[i] = createTreeNode(rand() % 100 + 1);
    }

    for (int i = 0; i < nodeCount; i++) {
        if (2 * i + 1 < nodeCount) {
            nodes[i]->left = nodes[2 * i + 1];
        }
        if (2 * i + 2 < nodeCount) {
            nodes[i]->right = nodes[2 * i + 2];
        }
    }

    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

void printTreeStructure(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    if (root->left != NULL || root->right != NULL) {
        printf("(");
        printTreeStructure(root->left);
        printf(", ");
        printTreeStructure(root->right);
        printf(")");
    }
}

/*
生成的二叉树结构如下：

           2
         /   \
       /       \
      4         7
    /   \      / \
   9     11  22  44
  / \   /
 66 88 99

*/
TreeNode* generateSpecificBinaryTree() 
{
    int values[] = {2, 4, 7, 9, 11, 22, 44, 66, 88, 99};
    int nodeCount = sizeof(values) / sizeof(values[0]);

    TreeNode** nodes = (TreeNode**)malloc(nodeCount * sizeof(TreeNode*));
    for (int i = 0; i < nodeCount; i++) {
        nodes[i] = createTreeNode(values[i]);
    }

    for (int i = 0; i < nodeCount; i++) {
        if (2 * i + 1 < nodeCount) {
            nodes[i]->left = nodes[2 * i + 1];
        }
        if (2 * i + 2 < nodeCount) {
            nodes[i]->right = nodes[2 * i + 2];
        }
    }

    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}