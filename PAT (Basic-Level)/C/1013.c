#include <stdio.h>
#include <math.h>

int judge_pri(int x);
int judge_pri(int x){
	int i, t;
	t = (int)sqrt((double)(x));
	for(i = 2; i <= t; i++){
		if(x % i == 0)
			return 0;
	
	    if(i > t)
	    	return 1;
	}
}

int main()
{
	int m, n;
	int i, j = 0, count = 0;
	scanf("%d %d", &m, &n);
	for(i = 2; count < n; i++){
		if(judge_pri(i) && (count+1) < m){
			count++;
		}
		else if(judge_pri(i) && (count+1) >= m){
			printf("%d", i);
			count++;
			j++;
			if(j % 10 == 0){
				printf("\n");
			}else if(j % 10 != 0 && count != n){
				printf(" ");
			}
		}
	}
	return 0;
}
