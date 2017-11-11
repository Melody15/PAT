#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char digit[10][6] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(int argc, char const *argv[]){
    char num[101];
    char ch;
    int count = 0;
    while((ch = getchar()) != '\n'){
        num[count++] = ch;
    }

    int sum = 0;
    for (int i = count-1; i >= 0; i--)
        sum += num[i] - 48;

    char sumChar[5];
    sprintf(sumChar, "%d", sum);
    int i = 0;
    int length = strlen(sumChar);
    while(1){
        if(sumChar[i] != '\0' && i < length-1){
            printf("%s ", digit[sumChar[i]-48]);
            i++;
        }else if(sumChar[i] != '\0' && i == length-1){
            printf("%s", digit[sumChar[i]-48]);
            break;
        }
    }
    return 0;
}