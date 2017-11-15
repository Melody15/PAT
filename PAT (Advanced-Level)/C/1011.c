#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    char result[3];
    double maxProfit = 1.0;
    for (int i = 0; i < 3; i++){
        double maxNum = 0.0;
        double tempNum;
        int temIndex;
        for (int j = 0; j < 3; j++){
            scanf("%lf", &tempNum);
            if(tempNum > maxNum){
                maxNum = tempNum;
                temIndex = j;
            }
        }
        maxProfit *= maxNum;

        if(temIndex == 0)
            result[i] = 'W';
        else if(temIndex == 1)
            result[i] = 'T';
        else if(temIndex == 2)
            result[i] = 'L';
    }
    maxProfit = (maxProfit * 0.65 - 1) * 2;
    for (int i = 0; i < 3; i++)
        printf("%c ", result[i]);
    printf("%.2f", maxProfit);
    return 0;
}