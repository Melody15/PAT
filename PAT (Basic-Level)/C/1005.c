#include <stdio.h>
#define N 100

int main(void)
{
	int n, Mark[N+1] = {0};
	scanf("%d", &n);
	int Num[n];
	
	for(int i = 0; i < n; i++){
		scanf("%d", &Num[i]);
		Mark[Num[i]] = 1;
	}
	
	for(int i = 0; i < n; i++){
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
	int j = 0;
	for(int i = 0; i <= N; i++){
		if(Mark[i] == 1){
			Num[j] = i;
			j++;
		}
	}
	j--;
	for(int i = j; i >= 0; i--){
		printf("%d", Num[i]);
		if(i > 0){
			printf(" ");
		}
	}
	return 0;
}
