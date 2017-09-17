#include <stdio.h>
#include <stdlib.h>

typedef struct studentInfo{
    int id;
    int moralScore;
    int talentScore;
}student;

int cmp(const void *a, const void *b){ //qsort's compare function
    student *c=(student*)a;  
    student *d=(student*)b;  
    int ret=0;  
    if((c->moralScore + c->talentScore) != (d->moralScore + d->talentScore)){  
        ret=(d->moralScore + d->talentScore) - (c->moralScore + c->talentScore);  
    }else{  
        if(d->moralScore != c->moralScore)
            ret=d->moralScore - c->moralScore;  
        else
            ret=c->id - d->id;
    }  
    return ret;  
}  

int main(int argc, char const *argv[]){
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    student rank1[N];
    student rank2[N];
    student rank3[N];
    student rank4[N];
    int tempID, tempMS, tempTS;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 0; i < N; i++){
        scanf("%d %d %d", &tempID, &tempMS, &tempTS);
        if(tempMS >= L && tempTS >= L){
            if(tempMS >= H && tempTS >= H){
                rank1[c1].id = tempID;
                rank1[c1].moralScore = tempMS;
                rank1[c1].talentScore = tempTS;
                c1++;;
            }else if(tempMS >= H && tempTS < H){
                rank2[c2].id = tempID;
                rank2[c2].moralScore = tempMS;
                rank2[c2].talentScore = tempTS;
                c2++;;
            }else if(tempMS < H && tempTS < H && tempMS >= tempTS){
                rank3[c3].id = tempID;
                rank3[c3].moralScore = tempMS;
                rank3[c3].talentScore = tempTS;
                c3++;;
            }else{
                rank4[c4].id = tempID;
                rank4[c4].moralScore = tempMS;
                rank4[c4].talentScore = tempTS;
                c4++;;
            }
        }
    }
    qsort(rank1, c1, sizeof(student), cmp);
    qsort(rank2, c2, sizeof(student), cmp);
    qsort(rank3, c3, sizeof(student), cmp);
    qsort(rank4, c4, sizeof(student), cmp);

    printf("%d\n", c1+c2+c3+c4);
    for (int i = 0; i < c1; i++)
        printf("%d %d %d\n", rank1[i].id, rank1[i].moralScore, rank1[i].talentScore);
    for (int i = 0; i < c2; i++)
        printf("%d %d %d\n", rank2[i].id, rank2[i].moralScore, rank2[i].talentScore);
    for (int i = 0; i < c3; i++)
        printf("%d %d %d\n", rank3[i].id, rank3[i].moralScore, rank3[i].talentScore);
    for (int i = 0; i < c4; i++)
        printf("%d %d %d\n", rank4[i].id, rank4[i].moralScore, rank4[i].talentScore);

    return 0;
}