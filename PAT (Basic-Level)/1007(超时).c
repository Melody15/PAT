#include <stdio.h>

int main(void)
{
	int n, i, j, t = 0, Mark = 0;
	scanf("%d", &n);
	int p_num[n];
	
	for(i = 2 ; i <= n ; i++){
		if(i%2 == 0 && i != 2)
	    continue;
		for(j = 2 ; j < n ; j++){
			if(i % j == 0){
				break;
			}
		}
		if(i == j || i == 2){
		    p_num[t] = i;
		    t++;
	    }
	}
	
	t--;
	for(t ; t > 0 ; t--){
		if(p_num[t]-p_num[t-1] == 2)
		Mark++;
    }
    
	printf("%d",Mark);
	
	return 0;
}
