#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
    int M, N, S;
    scanf("%d %d %d", &M, &N, &S);
    char peopleInfo[M+1][21];
    char winPeople[M][21];
    int winNum = 0;
    int flag; //flag = 1 means this people have won

    for (int i = 1; i <= M; i++)
        scanf("%s", peopleInfo[i]);

    if(M < S){
         printf("Keep going...\n");
         return 0;
    }   

    for (int i = S; i <= M; i += N){
        if(i == S){
            printf("%s\n", peopleInfo[i]);
            strcpy(winPeople[winNum++], peopleInfo[i]);
            continue;
        }

        flag = 1;
        while(flag != 0 && i <= M){
            for(int j = 0; j < winNum; j++){
                if(strcmp(peopleInfo[i], winPeople[j]) == 0){ //have won
                    i++;  //maybe excess the boundary, so while(&& i <= M)
                    break;
                }
                flag = 0; //haven't won
            } 
        }
        if(i > M) //excess the boundary
            break;

        printf("%s\n", peopleInfo[i]);
        strcpy(winPeople[winNum++], peopleInfo[i]);
    }

    return 0;
}