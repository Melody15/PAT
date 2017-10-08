#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char low[13][5] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
char high[13][4] = {"xxx","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

int main(int argc, char const *argv[]){
    int N;
    char data[10];
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++){
        gets(data);
        if(data[0] >= '0' && data[0] <= '9'){
            if(strlen(data) == 1)
                printf("%s\n", low[data[0]- '0']);
            else if(strlen(data) == 2){
                int temp = (data[0]-'0')*10 + (data[1]-'0');
                if(temp <= 12)
                    printf("%s\n", low[temp]);
                else if(temp%13 == 0)
                    printf("%s\n", high[temp/13]);
                else
                    printf("%s %s\n", high[temp/13], low[temp%13]);
            }else{
                int temp = (data[0]-'0')*100 + (data[1]-'0')*10 + (data[2]-'0');
                if(temp%13 == 0)
                    printf("%s\n", high[temp/13]);
                else
                    printf("%s %s\n", high[temp/13], low[temp%13]);
            }
        }else{ //mar2ear
            if(strlen(data) == 4)
                printf("0\n");
            else if(strlen(data) == 3){
                for (int i = 1; i < 13; i++){
                    if(data[0] == low[i][0] && data[1] == low[i][1] && data[2] == low[i][2])
                        printf("%d\n", i);
                    else if(data[0] == high[i][0] && data[1] == high[i][1] && data[2] == high[i][2])
                        printf("%d\n", i*13);
                }
            }else{
                int highNum, lowNum;
                for (int i = 0; i < 13; i++){
                    if(data[0] == high[i][0] && data[1] == high[i][1] && data[2] == high[i][2])
                        highNum = i;
                }
                for (int i = 0; i < 13; i++){
                    if(data[4] == low[i][0] && data[5] == low[i][1] && data[6] == low[i][2])
                        lowNum = i;
                }
                printf("%d\n", highNum*13 + lowNum);
            }

        }
    }
    return 0;
}