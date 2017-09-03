#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct examid{
    char passid[14+1];
    int testid;
}exam_id;

#define max 1000

int main()
{
    int N;
    int K;
    int a;
    scanf("%d\n", &N);
    exam_id record[max+1];
    int query[max+1];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 14; j++){
            record[0].passid[j] = getchar();
        }
        record[0].passid[14] = '\0';
        //printf("%s ", record[0].passid);
        scanf("%d %d", &a, &record[0].testid);
        strcpy(record[a].passid, record[0].passid);
        record[a].testid = record[0].testid;
        getchar();
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        scanf("%d", &query[i]);
    }
    for(int i = 0; i < K; i++){
        printf("%s ", record[query[i]].passid);
        printf("%d\n", record[query[i]].testid);
    }
    return 0;
}