#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
    char num[10000];
    scanf("%s", num);
    int length = strlen(num);
    int posE = 0;
    int exp = 0;

    if(num[0] == '-')
        printf("-");

    for (int i = 1; i < length; i++){
        if(num[i] == 'E')
            posE = i;
    }

    for (int i = posE + 2; i < length; i++){
        exp = (num[i] - '0') + 10 * exp;
    }

    if(num[posE + 1] == '-'){
        if(exp > 0){
            printf("0.");
            for (int i = 1; i < exp; i++)
                printf("0");
            for (int i = 1; i < posE; i++){
                if(num[i] >= '0' && num[i] <= '9')
                    printf("%c", num[i]);
            }
        }
        else{ //exp = 0
            for (int i = 1; i < posE; i++) 
                printf("%c", num[i]);
        }
    }else{
        if(posE - 3 < exp) {
            if(num[1] != '0')
                printf("%c", num[1]);
            for (int i = 3; i < posE; i++) {
                if (num[i] >= '0' && num[i] <= '9')
                    printf("%c", num[i]);
            }
            for (int i = 0; i < exp - (posE - 3); i++)
                printf("0");
        }
        else {
            if (num[1] != '0')
                printf("%c", num[1]);
            for (int i = 3; i < posE; i++) {
                if (i == 3 + exp)
                    printf(".");
                if (num[i] >= '0' && num[i] <= '9')
                    printf("%c", num[i]);
            }
        }
    }
    return 0;
}