#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int result[37] = {0};
    int temp;
    int friendnum = 0, count = 0;
    for (int i = 0; i < N; ++i)
    {
        friendnum = 0;
        scanf("%d", &temp);
        while(temp > 0){
            friendnum += (temp % 10);
            temp = temp / 10;
        }
        if(result[friendnum] == 0){
            count++;
            result[friendnum] = 1;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < 37; ++i)
    {
        if(result[i] == 1 && count != 1){
            printf("%d ", i);
            count--;
        }
        else if(result[i] == 1 && count == 1)
            printf("%d", i);
    }
    return 0;
}