#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int sum = 0, _0Times = 0, _1Times = 0;
    char ch;
    while((ch = getchar()) != '\n'){
        if(ch >= 'A' && ch <= 'Z'){
            sum += ch - 'A' + 1;
        }else if(ch >= 'a' && ch <= 'z'){
            sum += ch - 'a' + 1;
        }
    }
    while(sum != 0){  //模拟短除法进制转换
        if(sum % 2 == 0)
            _0Times++;
        else
            _1Times++;
        sum = sum/2;
    }
    printf("%d %d", _0Times, _1Times);

    return 0;
}