#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100000

typedef struct school
{
    int id;
    int score;
    struct school *next;
}Tschool, *Pschool;

int main()
{
    char sch_exist_flat[max+1]; //学校编号从1开始,下标为0的不用,所以长度+1 
    memset(sch_exist_flat, '0', sizeof(sch_exist_flat));
    int N;   
    int count = 0; 
    //int sch_max_num = 0;
    Tschool temprecord;
    Pschool phead;
    phead = (Pschool)malloc(sizeof(Tschool));
    phead->next = NULL;
    Pschool precord = phead;
    scanf("%d", &N);
    while(count < N){
        scanf("%d %d", &temprecord.id, &temprecord.score);
        if(sch_exist_flat[temprecord.id] == '0'){
            Pschool pnode;
            pnode = (Pschool)malloc(sizeof(Tschool));
            pnode->id = temprecord.id;
            pnode->score = temprecord.score;
            pnode->next = NULL;
            precord->next = pnode;
            precord = pnode;
            sch_exist_flat[temprecord.id] = '1';
        }else{
            Pschool ptemp = phead->next;
            while(ptemp->id != temprecord.id){
                ptemp = ptemp->next;
            }
            ptemp->score += temprecord.score;
        }
        count++;
    }

    temprecord.id = -1;
    temprecord.score = 0;
    Pschool ptemp2 = phead->next;
    while(ptemp2 != NULL){
        if(ptemp2->score > temprecord.score){
            temprecord.score = ptemp2->score;
            temprecord.id = ptemp2->id;
        }
        ptemp2 = ptemp2->next; 
    }
    printf("%d %d", temprecord.id, temprecord.score);
    return 0;
}
