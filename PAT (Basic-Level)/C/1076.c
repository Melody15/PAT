#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int N;
    scanf("%d\n", &N);
    char choice, answer;
    int result;
    for (int i = 0; i < N; i++){
        for (int i = 0; i < 4; i++){
            scanf("%c-%c", &choice, &answer);
            getchar();
            if(answer == 'T'){
                switch(choice){
                    case 'A': 
                    result = 1;
                    break;
                    case 'B': 
                    result = 2;
                    break;
                    case 'C': 
                    result = 3;
                    break;
                    case 'D': 
                    result = 4;
                    break;
                }
            }
        }
        printf("%d", result);
    }
    return 0;
}
