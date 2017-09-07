#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int singleNum[N];
    for (int i = 0; i < N; ++i){
        scanf("%d", &singleNum[i]);
    }
    int sum = 0;
    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){
            if(i != j && singleNum[i] != singleNum[j]){
                sum += singleNum[i]*10 + singleNum[j];
                sum += singleNum[j]*10 + singleNum[i];
            }else if(i != j && singleNum[i] == singleNum[j]){
                sum += singleNum[i]*10 + singleNum[j];
            }
        }
    }
    printf("%d", sum);
    return 0;
}