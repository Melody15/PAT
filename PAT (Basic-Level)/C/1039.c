#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 'z' //z的ascii码为122

int main()
{
    int flat = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int beads[max+1] = {0};
    char wanna;
    char exist_bead;
    while((wanna = getchar()) != '\n'){
            beads[wanna]++;
            count1++;
    }
    while((exist_bead = getchar()) != '\n'){
        count2++;
        if(beads[exist_bead] > 0){
            beads[exist_bead]--;
        }else{
            count3++;
            flat = 1;
        }
    }
    if(flat) printf("No %d", count3);
    else printf("Yes %d", count1 - count2);
}
