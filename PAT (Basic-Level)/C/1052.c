#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char hand[10+1][5];
    char eye[10+1][5];
    char mouth[10+1][5];
    char ch;
    int i = 1, j = 0, flag = 0;
    int handCount = 0, eyeCount = 0, mouthCount = 0;
    while((ch = getchar()) != '\n'){
        if(ch == '['){
        	while((ch = getchar()) != ']'){
                if(ch == '\n'){
                    flag = 1;
                    break; 
                }
                hand[i][j++] = ch;  
            }
            if (flag)
                break;
            hand[i][j] = '\0';   
            i++;  
            j = 0;  
        } 
        /*ch = getchar();  // this method would be overtime
        j = 0;
        while(ch != ']'){
            hand[i][j++] = ch;
            ch = getchar();
        }
        //current ch = ']'
        hand[i][j] = '\0';
        i++;*/
    }
    handCount = --i;

    i = 1; j = 0; flag = 0;
    while((ch = getchar()) != '\n'){
        if(ch == '['){
            while((ch = getchar()) != ']'){
                if(ch == '\n'){   
                    flag = 1;  
                    break; 
                }
                eye[i][j++] = ch;  
            }
            if (flag)
                break;
            eye[i][j] = '\0';   
            i++;  
            j = 0;  
        }
    }
    eyeCount = --i;

    i = 1; j = 0; flag = 0;
    while((ch = getchar()) != '\n'){
        if(ch == '['){
            while((ch = getchar()) != ']'){
                if(ch == '\n'){
                    flag = 1;  
                    break; 
                }
                mouth[i][j++] = ch;  
            }
            if (flag)
                break;
            mouth[i][j] = '\0';   
            i++;  
            j = 0; 
        }
    }
    mouthCount = --i;

    int N;
    int tempIndex[5];
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d %d %d %d", &tempIndex[0], &tempIndex[1], &tempIndex[2], &tempIndex[3], &tempIndex[4]);
        if(tempIndex[0] > handCount || tempIndex[1] > eyeCount || tempIndex[2] > mouthCount || tempIndex[3] > eyeCount || tempIndex[4] > handCount)
            printf("Are you kidding me? @\\/@\n");
        else if(tempIndex[0] <= 0 || tempIndex[1] <= 0 || tempIndex[2] <= 0 || tempIndex[3] <= 0 || tempIndex[4] <= 0)
            printf("Are you kidding me? @\\/@\n");
        else
            printf("%s(%s%s%s)%s\n", hand[tempIndex[0]], eye[tempIndex[1]], mouth[tempIndex[2]], eye[tempIndex[3]], hand[tempIndex[4]]);
    }
    return 0;
}
