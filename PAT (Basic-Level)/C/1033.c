#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 'z' //z的ascii码为122

int main()
{
    char badkey;
    char output;
    int useless[max+1] = {0};
   // printf("%d", max);
    while((badkey = getchar()) != '\n'){
        useless[badkey] = 1;
        if(badkey >= 'A' && badkey <= 'Z'){
            useless[badkey + 32] = 1;
        }
    }
    while((output = getchar()) != '\n'){
        if(useless[output] == 1) printf("");
        else if(useless['+'] == 1 && (output >= 'A' && output <= 'Z')) printf("");
        else printf("%c", output);
    }
    return 0;
}