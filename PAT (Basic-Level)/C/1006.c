#include <stdio.h>
int main()
{
	int n, i, tem;
	scanf("%d", &n);
	if(n >= 100){
		tem = n / 100;
		n = n - tem*100;
		for( i = 0 ; i < tem ; i++)
		printf("B");
	}
	
	if(n >= 10){
		tem = n / 10;
		n = n - tem*10;
		for( i = 0 ; i < tem ; i++)
		printf("S");
	}
	
	if(n != 0){
		for( i = 1 ; i <= n ; i++)
		printf("%d", i);
	}
	
	return 0;
}
