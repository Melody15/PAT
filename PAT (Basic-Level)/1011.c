#include <stdio.h>

int main()
{
	int i;
	int n;
	scanf("%d", &n);
	long int num[n][3];
	for(i = 0; i < n; i++){
		scanf("%ld %ld %ld", &num[i][0], &num[i][1], &num[i][2]);
	}
	for(i = 0; i < n; i++){
		if(num[i][0]+num[i][1] > num[i][2])
		printf("Case #%d: true\n", i+1);
		else
		printf("Case #%d: false\n", i+1);
	}
	return 0;
}
