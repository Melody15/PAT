#include <stdio.h>
#include <stdlib.h>

long int get_p(long int a, int da);
long int get_p(long int a, int da){
	int i, j = 0, k;
	long int pa = 0, tem = da;
	while(a != 0){
		i = a % 10;
		a = a / 10;
		if(i == da)
			j++;
	}
	for(i = j; i > 0; i--){
		tem = da;
		for(k = 0; k < i-1; k++){
			tem = tem*10;
		}
		pa += tem;
	}
	return pa;
}

int main()
{
	long int a, b;
	long int pa, pb; 
	int da, db;
	scanf("%ld %d %ld %d", &a, &da, &b, &db);
	//pa = get_p(a, da); 
	printf("%ld", get_p(a, da) + get_p(b, db));
	return 0; 
}
