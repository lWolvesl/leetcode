struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct Pair {
    int first;
    int second;
} Pair;

int getLength(struct ListNode* head){
    int len = 0;
    ListNode* node = head;
    while (node.next)
    {
        node = node.next;
        len++;
    }
    return len;
}

int* nextLargerNodes(struct ListNode* head, int* returnSize){
    int len = 0;
    struct ListNode* cur = head;
    while (cur) {
        cur = cur->next;
        len++;
    }
    int* ans = (int *)calloc(len, sizeof(int));
    Pair stack[len];
    int top = 0, pos = 0;

    cur = head;
    int idx = -1;
    while (cur) {
        ++idx;
        ans[pos++] = 0;
        while (top > 0 && stack[top - 1].first < cur->val) {
            ans[stack[top - 1].second] = cur->val;
            top--;
        }
        stack[top].first = cur->val;
        stack[top].second = idx;
        top++;
        cur = cur->next;
    }
    *returnSize = len;
    return ans;
}