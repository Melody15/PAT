#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main(void)
{
	struct mons {
		int coe;  //coefficient
		int ind;  //index
	} *mon[N];
	
	int i, M;
	for(i=0;i<N;i++){
		mon[i] = calloc(1, sizeof(struct mons));
	}
	
	for(i=0;i<N;i++){
        scanf("%d %d", &mon[i]->coe, &mon[i]->ind);
        if(getchar() == '\n')
        break;
    }
    M = i;
    
    for(i=0;i<=M;i++){
    	if(mon[i]->coe==0){
    		printf("0 0");
		}else if(mon[i]->ind==0){
			;
		}else {
			printf("%d %d", (mon[i]->coe)*(mon[i]->ind), mon[i]->ind-1);
		}
		
		if(i<M && mon[i+1]->ind!=0){
		printf(" ");
	    }
	}
	return 0;
}
