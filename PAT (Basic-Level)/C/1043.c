#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int chset[6] = {0};
    char ch;
    int test = 0;
    while((ch = getchar()) != '\n'){
        if(ch == 'P') chset[0]++;
        else if(ch == 'A') chset[1]++;
        else if(ch == 'T') chset[2]++;
        else if(ch == 'e') chset[3]++;
        else if(ch == 's') chset[4]++;
        else if(ch == 't') chset[5]++;
    }
    for(int i = 0; i < 6; i++)
        test += chset[i];

    while(test != 0){
        for(int i = 0; i < 6; i++){
            if(chset[i] > 0){
                switch(i){
                    case 0:
                        printf("P");
                        chset[i]--;
                        break;
                    case 1:
                        printf("A");
                        chset[i]--;
                        break;
                    case 2:
                        printf("T");
                        chset[i]--;
                        break;
                    case 3:
                        printf("e");
                        chset[i]--;
                        break;
                    case 4:
                        printf("s");
                        chset[i]--;
                        break;
                    case 5:
                        printf("t");
                        chset[i]--;
                        break;
                }
            }
        }
        test = 0;
        for(int i = 0; i < 6; i++)
            test += chset[i];
    }
    return 0;
}