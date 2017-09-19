#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);  //if a and b don't have greatest common divisor, return 1
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

void swap(int *a, int *b);
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[]){
    int  numerator1, denominator1,  numerator2, denominator2, K;
    scanf("%d/%d %d/%d %d", &numerator1, &denominator1, &numerator2, &denominator2, &K);
    if(numerator1 * denominator2 > numerator2 * denominator1){
        swap(&numerator1, &numerator2);
        swap(&denominator1, &denominator2);
    }
    int resultNumerator = numerator1*K/denominator1 + 1;
    int flag = 0;
    while(resultNumerator*denominator1 > numerator1*K && resultNumerator*denominator2 < numerator2*K){
        if(gcd(resultNumerator, K) == 1){
            if(flag == 0)
                flag = 1;
            else
                printf(" ");
            printf("%d/%d", resultNumerator, K);
        }
        resultNumerator++;
    }

    return 0;
}
//reference:http://blog.csdn.net/wanmeiwushang/article/details/53914918
