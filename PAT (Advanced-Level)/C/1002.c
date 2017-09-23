#include <stdio.h>

int main(int argc, char const *argv[]){
    float result[1000+1] = {0};
    int K1, K2, KResult;
    int exponent;
    float coefficient;
    scanf("%d", &K1);
    for (int i = 0; i < K1; i++){
        scanf("%d %f", &exponent, &coefficient);
        result[exponent] += coefficient;
    }

    scanf("%d", &K2);
    for (int i = 0; i < K2; i++){
        scanf("%d %f", &exponent, &coefficient);
        result[exponent] += coefficient;
    }
    for (int i = 0; i <= 1000; i++){
        if(result[i] != 0)
            KResult++;
    }
    printf("%d", KResult);
    for (int i = 1000; i >= 0; i--){
        if(result[i] != 0)
            printf(" %d %.1f", i, result[i]);
    }
    return 0;
}