#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
    int min1, min2, minute;    
    char day, hour;
    int count = 0;
    char s1[60], s2[60], s3[60], s4[60];
    scanf("%s", s1); int lengths1 = strlen(s1);
    scanf("%s", s2); int lengths2 = strlen(s2);
    scanf("%s", s3); int lengths3 = strlen(s3);
    scanf("%s", s4); int lengths4 = strlen(s4);
    min1 = lengths1 <= lengths2 ? lengths1 : lengths2;
    min2 = lengths3 <= lengths4 ? lengths3 : lengths4;

    for (int i = 0; i < min1; i++){
        if(s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[i]){
            day = s1[i];
            count = i;
            break;
        }
    }
    switch(day) {
        case 'A' : printf("MON "); break;
        case 'B' : printf("TUE "); break;
        case 'C' : printf("WED "); break;
        case 'D' : printf("THU "); break;
        case 'E' : printf("FRI "); break;
        case 'F' : printf("SAT "); break;
        case 'G' : printf("SUN "); break;
        default : break;
    }

    for (int i = count + 1; i < min1; i++){
        if(((s1[i] >= 'A' && s1[i] <= 'N') || (s1[i] >= '0' && s1[i] <= '9')) && s1[i] == s2[i]){
            hour = s1[i];
            break;
        }
    }

    if(hour >= '0' && hour <= '9'){
        printf("%.2d:", hour - 48);
    }else{
        printf("%d:", hour - 55);
    }

    for (int i = 0; i < min2; i++){
        if(((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z')) && s3[i] == s4[i])
            minute = i;
    }
    printf("%.2d", minute);
    return 0;
}