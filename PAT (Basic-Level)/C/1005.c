#include <stdio.h>
#define N 100

int main(void)
{
	int n, i, j = 0, Mark[N+1] = {0};
	scanf("%d", &n);
	int Num[n];
	
	for(i = 0 ; i < n ; i++){
		scanf("%d", &Num[i]);
		Mark[Num[i]] = 1;
	}
	
	for(i = 0 ; i < n ; i++){
		while(Num[i] != 1) {
		    if((Num[i] % 2) == 1){
			    Num[i] = ( 3*Num[i] + 1) / 2;  
			    if(Num[i] <= 100)
				Mark[Num[i]] = 0;
		    }else{
			    Num[i] = Num[i] / 2;
			    if(Num[i] <= 100)
			    Mark[Num[i]] = 0;
		    }
	    }
	}
	
	for(i = 0 ; i <= N ; i++){
		if(Mark[i] == 1){
			Num[j] = i;
			j++;
		}
	}
	j--;
	for(j ; j >= 0 ; j--){
		printf("%d", Num[j]);
		if(j>0){
			printf(" ");
		}
	}
	return 0;
}
