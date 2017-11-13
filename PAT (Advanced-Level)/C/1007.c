#include <stdio.h>

int main(int argc, char const *argv[]){
    int N;
    scanf("%d", &N);
    int sequence[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &sequence[i]);

    int tempsum = 0, tempLeftIndex = 0;
    int sum = -1;
    int leftIndex = 0, rightIndex = N-1;

    for (int i = 0; i < N; i++){
        tempsum += sequence[i];
        if(tempsum < 0){
            tempsum = 0;
            tempLeftIndex = i+1;
        }else if(tempsum > sum){
            sum = tempsum;
            leftIndex = tempLeftIndex;
            rightIndex = i;
        }
    }
    //while all the numbers are nagetive, sum would be less than zero, and left = 0, right = N-1. If there exists positive number, sum would be more than 0.
    if(sum < 0)
        sum = 0;
    printf("%d %d %d", sum, sequence[leftIndex], sequence[rightIndex]);
    return 0;
}