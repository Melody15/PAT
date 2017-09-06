#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000

int main()
{
    int N;
    int group[max+1] = {0};
    int group_num, people_num, score;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d-%d %d", &group_num, &people_num, &score);
        group[group_num] += score;
    }
    int max_group_num = 1;
    for(int i = 1; i < 1001; i++){
        if(group[i] > group[max_group_num]) max_group_num = i;
    }
    printf("%d %d", max_group_num, group[max_group_num]);
    return 0;
}