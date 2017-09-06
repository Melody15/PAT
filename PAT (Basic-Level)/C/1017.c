#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char A[1001];
    int B;
    char ch;
    int length = 0, sum = 0;
    while((ch = getchar()) != ' '){
        A[length++] = ch;
    }
    scanf("%d", &B);
    for(int i = 0; i < length; i++){
        sum = sum*10 + A[i] - '0';
        if(sum >= B){
            printf("%d", sum/B);
        }else if(sum < B && i == 0 && length > 1); //第一位不够除时也不输出0,并且A为非一位数
        else{
            printf("0");
        }
        sum = sum % B;
    }
       
    printf(" %d", sum);
    return 0;
}