#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 128

int main()
{
    char ch;
    int ascii[max] = {0};
    int count = 0;
    while((ch = getchar()) != '\n'){
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
            if(ch >= 'A' && ch <= 'Z')
                ascii[ch + 32]++;
            else if(ch >= 'a' && ch <= 'z')
                ascii[ch]++;
        }
    }
    for(int i = 0; i < max; i++){
        if(ascii[i] > count) {
            count = ascii[i];
            ch = (char)i;
        }
    }
    printf("%c %d", ch, count);
    return 0;
}