#include <stdio.h>
#define N 10000

int main()
{
	int i, k, j = 1;
	int a[N];
	a[j] = 2;
	j++;
	for(i = 3; i < N; i++){
		for(k = 2; k < i; k++){
			if(i%k == 0){
				break;
			}
			if(k == i-1){
				a[j] = i;
				j++;
			}
		}
	}
	int m, n;
	int count = 0;
	scanf("%d %d", &m, &n);
	for(i = m; i < n; i++){
		if(count == 9){
			printf("%d\n", a[i]);
			count = 0;
			continue;
		}
		printf("%d ", a[i]);
		count++;
	}
	printf("%d", a[n]);
	return 0;
}
