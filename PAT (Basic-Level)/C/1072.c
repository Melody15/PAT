#include <stdio.h>

int main(int argc, char const *argv[]){
    int N, M, K, tempThing;
    scanf("%d %d", &N, &M);
    int checkThings[M];
    char stuName[10];
    int studentsChecked = 0;
    int thingsChecked = 0;
    for (int i = 0; i < M; i++){
        scanf("%d", &checkThings[i]);
    }
    int first = 0;
    for (int i = 0; i < N; i++){
        scanf("%s %d", stuName, &K);
        first = 0;
        for (int i = 0; i < K; i++){
            scanf("%d", &tempThing);
            for (int i = 0; i < M; i++){
                if(tempThing == checkThings[i]){
                    if(first == 0){
                        printf("%s: %04d", stuName, tempThing); //must be %04d !
                        studentsChecked++;
                        thingsChecked++;
                        first = 1;
                    }else{
                        printf(" %04d", tempThing);
                        thingsChecked++;
                    }
                }
            }
        }
        if(first == 1)
            printf("\n");
    }
    printf("%d %d", studentsChecked, thingsChecked);
    return 0;
}