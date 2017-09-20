#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
    int N;
    scanf("%d", &N);
    char str[50];       //str[20] is too small
    char str2[50];
    double temp, sum = 0;
    int count = 0;
    int flag = 0;

    for (int i = 0; i < N; i++){
        flag = 0;
        scanf("%s", str);
        sscanf(str, "%lf", &temp);  //argument 3 expects argument of type 'type *'
        sprintf(str2, "%.2f", temp);
        for (int i = 0; i < strlen(str); i++){
            if(str[i] != str2[i])
                flag = 1;
        }
        if(flag || temp < -1000 || temp > 1000)
            printf("ERROR: %s is not a legal number\n", str);
        else{
            sum += temp;
            count++;
        }
    }
    if(count == 0)
        printf("The average of 0 numbers is Undefined");
    else if(count == 1)
        printf("The average of 1 number is %.2lf", sum);
    else
        printf("The average of %d numbers is %.2lf", count, sum / count);
    return 0;
}

//reference：https://www.liuchuo.net/archives/617
