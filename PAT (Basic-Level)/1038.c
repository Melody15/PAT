#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, K;
    int count;
    scanf("%d", &N);
    short int score[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &score[i]);
    }

    scanf("%d", &K);
    short int query[K];
    for(int j = 0; j < K; j++){
        scanf("%d", &query[j]);
    }

    for(int j = 0; j < K; j++){
        count = 0;
        for(int i = 0; i < N; i++){
            if(query[j] == score[i]) count++;
        }
        if(j < K - 1) printf("%d ", count);
        else if (j == K - 1) printf("%d", count);
    }
    return 0;
}
