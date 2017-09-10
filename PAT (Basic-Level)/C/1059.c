#include <stdio.h>
#include <math.h>

typedef struct id{
    int rank;   //student's rank
    int flag;   //whether has been assessed, 1 means assessed
}id;

int isPrime(int a) { //juedge whether prime
    if(a <= 1) return 0;
    int Sqrt = sqrt((double)a);
    for(int i = 2; i <= Sqrt; i++) {
        if(a % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[]){
    id idInfo[10000]; //index is the student's id
    for (int i = 1000; i < 10000; i++){
        idInfo[i].rank = 0;
        idInfo[i].flag = 0;
    }

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        int idnum;
        scanf("%d", &idnum);
        idInfo[idnum].rank = i;
    }
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++){
        int idnum;
        scanf("%d", &idnum);
        if(idInfo[idnum].rank != 0 && idInfo[idnum].flag == 0){
            if(idInfo[idnum].rank == 1)
                printf("%04d: Mystery Award\n", idnum);
            else if(idInfo[idnum].rank != 1 && isPrime(idInfo[idnum].rank))
                printf("%04d: Minion\n", idnum);
            else
                printf("%04d: Chocolate\n", idnum);
            idInfo[idnum].flag = 1;
        }else if(idInfo[idnum].rank == 0)
            printf("%04d: Are you kidding?\n", idnum);
        else if(idInfo[idnum].rank != 0 && idInfo[idnum].flag == 1)
            printf("%04d: Checked\n", idnum);
    }
    return 0;
}

//原来是可以使用交互式的输出的...就是说输入和输出混在一起并没有关系..