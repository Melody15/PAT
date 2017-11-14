#include <stdio.h>

int main(int argc, char const *argv[]){
    int k, a;
    double input[1000+1] = {0.0};
    double result[2000+1] = {0.0};
    double b;

    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        scanf("%d %lf", &a, &b);
        input[a] = b;
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        scanf("%d %lf", &a, &b);
        for (int j = 0; j <= 1000; j++){
            result[j+a] += input[j]*b;
        }
    }
    int count = 0;
    for (int i = 0; i <= 2000; i++){
        if(result[i] != 0.0)
            count++;
    }
    printf("%d", count);

    for (int i = 2000; i >= 0; i--){
        if(result[i] != 0.0)
            printf(" %d %.1f", i, result[i]);
    }
    return 0;
}