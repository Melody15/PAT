#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
    int a, b;
    scanf("%d %d", &a, &b);
    char num[10];
    if(a + b < 0){
        printf("-");
        sprintf(num, "%d", -(a+b));
    }else
        sprintf(num, "%d", (a+b));
    //printf("%s", num);
    int k = (strlen(num)-1) % 3;
    for (int i = 0; i < strlen(num); i++){
        printf("%c", num[i]);
        if((i-k) % 3 == 0 && i != strlen(num) - 1)
            printf(",");
    }
    return 0;
}