#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int N;
    scanf("%d", &N);
    int floor[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &floor[i]);
    
    int sumTime = 0;
    int presentFloor = 0, previousFloor = 0;
    for (int i = 0; i < N; i++){
        presentFloor = floor[i];
        if(presentFloor > previousFloor)
            sumTime += (presentFloor - previousFloor)*6;
        else if(presentFloor < previousFloor)
            sumTime += (previousFloor - presentFloor)*4;
        sumTime += 5;
        previousFloor = floor[i];
    }
    printf("%d", sumTime);
    return 0;
}