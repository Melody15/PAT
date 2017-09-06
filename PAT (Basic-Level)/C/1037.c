#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b);

int main()
{
    int gallonp, sicklep, knutp;
    int gallona, sicklea, knuta;
    int gallonr, sickler, knutr;
    int flat = 0;
    scanf("%d.%d.%d", &gallonp, &sicklep, &knutp);
    scanf("%d.%d.%d", &gallona, &sicklea, &knuta);

    if((gallona < gallonp) || (gallona == gallonp && (sicklea < sicklep)) || ((gallona == gallonp) && (sicklea == sicklep) && (knuta < knutp))){
        swap(&gallona, &gallonp);
        swap(&sicklea, &sicklep);
        swap(&knuta, &knutp);
        flat = 1;
    }

    if(knuta < knutp){
        knutr = knuta + 29 - knutp;
        sicklea--;
    }else{
        knutr = knuta - knutp;
    }

    if(sicklea < sicklep){
        sickler = sicklea + 17 - sicklep;
        gallona--;
    }else{
        sickler = sicklea - sicklep;
    }

    gallonr = gallona - gallonp;

    if(flat) printf("-%d.%d.%d", gallonr, sickler, knutr);
    else printf("%d.%d.%d", gallonr, sickler, knutr);
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}