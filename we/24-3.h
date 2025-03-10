struct List{
    int val;
    struct List * next;
};

void bubbleListSort(List *head) {
    if (head == nullptr) return; // 空链表检查
    
    List *temp2;
    int temp;
    bool swapped;
    do {
        swapped = false;
        temp2 = head;
        while (temp2->next) {
            if (temp2->next->val < temp2->val) {
                temp = temp2->val;
                temp2->val = temp2->next->val;
                temp2->next->val = temp;
                swapped = true;
            }
            temp2 = temp2->next;
        }
    } while (swapped); // 如果没有发生交换，提前结束
}