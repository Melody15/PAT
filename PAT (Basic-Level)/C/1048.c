#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int main()
{
    char code_dict[max+1];
    char code[max+1];
    int count = 0;
    int count2 = 0;
    int max_len;
    char ch;
    while((ch = getchar()) != ' '){
        code_dict[++count] = ch;
    }
    while((ch = getchar()) != '\n'){
        code[++count2] = ch;
    }
    if(count2 > count)
        max_len = count2;
    else
        max_len = count;
        
    char outcome[max_len + 1];
    for(int i = 0; i < max_len + 1; i++) outcome[i] = '0';

    for(int i = 0; i < count; i++){
        int temp;
        if((i % 2) == 0){   //奇数
            if((count2-i) >= 1)
                temp = ((code_dict[count-i] - 48) + (code[count2-i] - 48)) % 13;
            else
                temp = (code_dict[count-i] - 48) % 13;
            if(temp == 12) outcome[max_len-i] = 'K';
            else if(temp == 11) outcome[max_len-i] = 'Q';
            else if(temp == 10) outcome[max_len-i] = 'J';
            else outcome[max_len-i] = (char)(temp + 48);
        }else{
            if((count2-i) >= 1)
                temp = (code[count2-i] - 48) - (code_dict[count-i] - 48);
            else
                temp = ('0' - 48) - (code_dict[count-i] - 48);
            if(temp < 0) temp += 10;
            if(temp == 12) outcome[max_len-i] = 'K';
            else if(temp == 11) outcome[max_len-i] = 'Q';
            else if(temp == 10) outcome[max_len-i] = 'J';
            else outcome[max_len-i] = (char)(temp + 48);
        }
    }
    if(count2 > count){
        for(int i = 1; i <= (count2 - count); i++){
            outcome[i] = code[i];
        }
    }
    for(int i = 1; i < max_len + 1; i++){
        printf("%c", outcome[i]);
    }
    return 0;
}
