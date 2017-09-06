#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char use;
    int N, row;
    scanf("%d %c", &N, &use);
    if((N % 2) == 0) row = N/2;
    else row = N/2 + 1;
    
    for(int j = 0; j < row; j++){
        if(j == 0 || j == row -1){
            for(int i = 0; i < N; i++){
                printf("%c", use);
            }
            printf("\n");
        }
        else{
            int k = 0;
            while(k < N){
                if(k == 0 || k == N-1){
                    printf("%c", use);
                }else printf(" ");
                k++;
            }
            printf("\n");
        }
    }
    return 0;
}