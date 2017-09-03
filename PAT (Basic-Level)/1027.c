#include <stdio.h>

int main()
{
	int n, remain;
	char ch;
	scanf("%d %c", &n, &ch);
	int i = 1;
	while((2*i*i - 1) <= n){
		i++;
	}
	i--;

	remain = n - 2*i*i + 1;
	int j = 2 * i - 1 ;
	int max = j;
	while(j > 0){
		int tem = i;
		for(tem; tem < (max + 1)/2; tem++)
			printf(" ");
		for(j; j > 0; j--)
			printf("%c", ch);
		printf("\n");
		i--;
		j = 2 * i - 1;
	}
	i += 2;
	j = 2 * i - 1;
	while(j <= max){
		int tem = i;
		for(tem; tem < (max + 1)/2; tem++)
			printf(" ");
		for(j; j > 0; j--)
			printf("%c", ch);
		printf("\n");	
		i++;
		j = 2 * i - 1;
	}
	printf("%d", remain);
	return 0;	
}
