#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, K;
    //int count;
    scanf("%d", &N);
    int score[N];
    int grade[100 + 1] = {0};
    for(int i = 0; i < N; i++){
        scanf("%d", &score[i]);
        grade[score[i]]++;
    }

    scanf("%d", &K);
    int query[K];
    for(int j = 0; j < K; j++){
        scanf("%d", &query[j]);
    }

    for(int j = 0; j < K; j++){
        if(j < K - 1) printf("%d ", grade[query[j]]);
        else if (j == K - 1) printf("%d", grade[query[j]]);
    }
}