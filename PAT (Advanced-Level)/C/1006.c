#include <stdio.h>
#include <stdlib.h>

typedef struct Info{
    char id[15+1];
    int inHour, inMin, inSec;
    int outHour, outMin, outSec;
}info;

int main(int argc, char const *argv[]){
    int M;
    scanf("%d", &M);
    info record[M];
    for (int i = 0; i < M; i++){
        scanf("%s", record[i].id);
        scanf("%d:%d:%d", &record[i].inHour, &record[i].inMin, &record[i].inSec);
        scanf("%d:%d:%d", &record[i].outHour, &record[i].outMin, &record[i].outSec);
    }
    int earlyHour, earlyMin, earlySec, earlyId;
    int lateHour, lateMin, lateSec, lateId;
    earlyHour = record[0].inHour; earlyMin = record[0].inMin; 
    earlySec = record[0].inSec; earlyId = 0;
    lateHour = record[0].outHour; lateMin = record[0].outMin; 
    lateSec = record[0].outSec; lateId = 0;

    for (int i = 1; i < M; i++){
        if(record[i].inHour < earlyHour || (record[i].inHour == earlyHour && record[i].inMin < earlyMin) || (record[i].inHour == earlyHour && record[i].inMin == earlyMin && record[i].inSec < earlySec)){
            earlyHour = record[i].inHour; earlyMin = record[i].inMin;
            earlySec = record[i].inSec; earlyId = i; 
        }
        if(record[i].outHour > lateHour || (record[i].outHour == lateHour && record[i].outMin > lateMin) || (record[i].outHour == lateHour && record[i].outMin == lateMin && record[i].outSec > lateSec)){
            lateHour = record[i].outHour; lateMin = record[i].outMin; 
            lateSec = record[i].outSec; lateId = i;
        }
    }

    printf("%s %s", record[earlyId].id, record[lateId].id);
    return 0;
}
