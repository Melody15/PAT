#include <stdio.h>

int main()
{
	int pri[10] = {0};
	char num[1000];
	char ch;
	int i = 0, j;
	while((ch = getchar()) != '\n'){
		num[i] = ch;
		i++;
	}
	for(j = 0; j < i; j++){
		pri[num[j]-48]++;
	}
	for(i = 0; i < 10; i++){
		if(pri[i] != 0){
			printf("%d:%d\n", i, pri[i]);
		}
	}
	return 0;
}
