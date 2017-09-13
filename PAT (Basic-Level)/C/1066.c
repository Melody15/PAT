#include <stdio.h>

int main(int argc, char const *argv[]){
    int M, N, A, B, replaceNum;
    scanf("%d %d %d %d %d", &M, &N, &A, &B, &replaceNum);
    int temp;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &temp);
            if(temp >= A && temp <= B)
                temp = replaceNum;
            printf("%03d", temp);
            if(j == N-1)
                printf("\n");
            else 
                printf(" ");
        }
    }
    return 0;
}