#include <stdio.h>

int main(int argc, char const *argv[]){
    int T, K;
    scanf("%d %d", &T, &K);
    int n1, b, t, n2;
    for (int i = 0; i < K; i++){
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        if(t > T){
            printf("Not enough tokens.  Total = %d.\n", T);
        }
        else if((b == 0 && n1 > n2) || (b == 1 && n1 < n2)){
            T += t;
            printf("Win %d!  Total = %d.\n", t, T);
        }else if((b == 0 && n1 < n2) || (b == 1 && n1 > n2)){
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
            if(T == 0){
                printf("Game Over.\n");
                break;
            }
        }
    }
    return 0;
}