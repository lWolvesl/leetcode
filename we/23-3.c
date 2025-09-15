#include <stdlib.h>
#include <stdio.h>

struct student{
    int stuId;
    char *name;
    int score;
};

void inputData(struct student *s, int size){
    for(int i = 0; i < size; i++){
        printf("请输入第%d个学生的学号、姓名、成绩：", (i + 1));
        printf("学生学号：");
        scanf("%d", &s[i].stuId);
        s[i].name = (char *)malloc(50 * sizeof(char));
        if (s[i].name == NULL)
        {
            printf("内存分配失败\n");
        }
        
        printf("学生姓名：");
        scanf("%s", s[i].name);
        printf("学生成绩：");
        scanf("%d", &s[i].score);
    }
}

void bubbleSort(struct student *s, int size){
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size-i-1;j++){
            if(s[j].score > s[j+1].score){
                struct student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

struct student *findScore(struct student *s, int size, int score){
    int left = 0;
    int right = size - 1;
    int mid;
    while(left <= right){
        mid = left + (right - left) / 2;
        if(s[mid].score == score){
            return &s[mid];
        }else if (s[mid].score > score){
            right = mid - 1;
        }else
        {
            left = mid + 1;
        }
    }
    return NULL;
}

int main(){
    int size;
    printf("请输入学生人数：");
    scanf("%d",&size);
    struct student *s = (struct student *)malloc(sizeof(struct student)*size);
    inputData(s, size);
    bubbleSort(s, size);
    for(int i = 0;i<size;i++){
        printf("学号：%d，姓名：%s，成绩：%d\n", s[i].stuId, s[i].name, s[i].score);
    }
    printf("请输入要查找学生的成绩：");
    int score;
    scanf("%d",&score);
    struct student *p = findScore(s, size, score);
    if(p == NULL){
        printf("未找到此成绩的学生\n");
    }else{
        printf("学号：%d，姓名：%s，成绩：%d\n",p->stuId,p->name,p->score);
    }

    for (int i = 0; i < size; i++)
    {
        free[s[i].name];
    }

    free(s);
    
    return 0;
}