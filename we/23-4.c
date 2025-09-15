#include <stdlib.h>
#include <stdbool.h>

struct Toy
{
    int val;   // 玩具的编号
    struct Toy *next;
};

void print(struct Toy *head){
    struct Toy *temp = head->next;
    while(temp != NULL){
        printf("%d-",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

struct Toy *createToy(int val){
    struct Toy *t = (struct Toy *)malloc(sizeof(struct Toy));
    if(t == NULL){
        return NULL;
    }
    t->val = val;
    return t;
}

bool init(struct Toy *head){
    struct Toy *temp = head;
    for(int i = 1;i<=10;i++){
        temp->next = createToy(i);
        temp = temp->next;
        if(temp == NULL){
            return false;
        }
    }
    return true;
}

void game(struct Toy *head,int val){
    struct Toy *temp = head;
    while (temp->next != NULL)
    {
        if(temp->next->val == val){
            break;
        }
        temp = temp->next;
    }

    struct Toy *t = temp->next;
    temp->next = t->next;
    t->next = head->next;
    head->next = t;
}

int main(){
    struct Toy *head = createToy(-1); //头节点
    if(head == NULL){
        printf("malloc fail\n");
        return -1;
    }
    bool in = init(head);
    if(in == false){
        printf("init fail\n");
        return -1;
    }

    print(head);

    game(head,3); // 骰子数为3
    print(head);
    return 0;
}