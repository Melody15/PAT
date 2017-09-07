#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    char A, B;
    int AWinTimes = 0, AFailTimes = 0, AEqualTimes = 0;
    int AWinByC = 0, AWinByJ = 0, AWinByB = 0;
    int BWinByC = 0, BWinByJ = 0, BWinByB = 0;
    getchar(); //clear the '\n'
    for (int i = 0; i < N; ++i)
    {
        scanf("%c %c", &A, &B);
        getchar();//clear the '\n'
        if((A == 'C' && B == 'J') || (A == 'J' && B == 'B') || (A == 'B' && B == 'C')){
            AWinTimes++;
            if(A == 'C')
                AWinByC++;
            if(A == 'J')
                AWinByJ++;
            if(A == 'B')
                AWinByB++;
        }
        else if(A == B)
            AEqualTimes++;
        else{
            AFailTimes++;
            if(A == 'C')
                BWinByB++;
            if(A == 'J')
                BWinByC++;
            if(A == 'B')
                BWinByJ++;
        }
    }
    printf("%d %d %d\n", AWinTimes, AEqualTimes, AFailTimes);
    printf("%d %d %d\n", AFailTimes, AEqualTimes, AWinTimes);
    if((AWinByB >= AWinByC) && (AWinByB >= AWinByJ))
        printf("B");
    else if(AWinByC >= AWinByJ)
        printf("C");
    else
        printf("J");

    if((BWinByB >= BWinByC) && (BWinByB >= BWinByJ))
        printf(" B");
    else if(BWinByC >= BWinByJ)
        printf(" C");
    else
        printf(" J");
    return 0;
}
