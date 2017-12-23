#include <stdio.h>

int main(int argc, char const *argv[]){
    char control, ch = '\n', nextCh;
    char str[1001];
    int countNum[1001];
    int count = 1, i = 0;
    control = getchar(); 
    getchar(); //除去回车
    if(control == 'C'){
        while((nextCh = getchar()) != '\n'){
            while(ch == nextCh){
                count++;
                ch = nextCh;
                nextCh = getchar();
            }
            if(ch != '\n'){
                str[i] = ch;
                countNum[i++] = count;
            }
            count = 1;
            ch = nextCh;
            if(ch == '\n')
                break;
        }
        if(ch != '\n'){ //输入为'\n'或者以单字符结尾
            str[i] = ch;
            countNum[i++] = count;
        }
        for (int j = 0; j < i; j++){
            if(countNum[j] != 1)
                printf("%d%c", countNum[j], str[j]);
            else
                printf("%c", str[j]);
        }
    }else if(control == 'D'){
        ch = getchar();
        while(1){
            count = 1;
            int Times = 1;
            if(ch >= '0' && ch <= '9'){
                count = ch - '0';
                Times *= 10;
                nextCh = getchar();
                while(nextCh >= '0' && nextCh <= '9'){
                    count = count*Times + nextCh - '0';
                    nextCh = getchar();
                }
                for (int i = 0; i < count-1; i++)
                    printf("%c", nextCh);
            }else{
                nextCh = getchar();
                printf("%c", ch);
            }
            ch = nextCh;
            if(ch == '\n')
                break;
        }
        printf("\n");
    }
    return 0;
}