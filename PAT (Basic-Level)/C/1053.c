#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N, D;
    double e;
    scanf("%d %lf %d", &N, &e, &D);
    int proEmptyCount = 0, emptyCount = 0;
    for (int i = 0; i < N; ++i)
    {
        int obserDays;
        scanf("%d", &obserDays);
        int eleLessDays = 0;
        for (int j = 0; j < obserDays; ++j)
        {           
            double eleUsed;
            scanf("%lf", &eleUsed);
            if(eleUsed < e) eleLessDays++;
        }
        if(eleLessDays > (obserDays/2) && obserDays > D) emptyCount++;
        else if(eleLessDays > (obserDays/2) && obserDays <= D) proEmptyCount++;
    }
    printf("%.1f%% %.1f%%", (double)proEmptyCount/N * 100, (double)emptyCount/N * 100);
    return 0;
}