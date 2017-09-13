#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
    char password[21];
    int limitTimes;
    int enterTimes = 0;
    scanf("%s %d", password, &limitTimes);
    getchar(); // clear the '\n', use this because clientEnter could be nothing
    char clientEnter[100];
    while(1){
        //scanf("%s", clientEnter); //the password doesn't contain space but the clientEnter could contain, could not use scanf but gets()
        gets(clientEnter);
        if(strcmp(clientEnter, "#") == 0) //could not use if(clientEnter[0] == '#')
            break;
        enterTimes++;
        if(strcmp(clientEnter, password) != 0 && enterTimes <= limitTimes){
            printf("Wrong password: %s\n", clientEnter);
            if(enterTimes == limitTimes){
                printf("Account locked");
                break;
            }
        }
        else if(strcmp(clientEnter, password) == 0 && enterTimes <= limitTimes){
            printf("Welcome in");
            break;
        }
    }
    return 0;
}