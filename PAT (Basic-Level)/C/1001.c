#include <stdio.h>

int main(void)
{
	int num, i = 0;
	scanf("%d", &num);
	while(num! = 1){
		if((num % 2) == 1){
			num = (3*num + 1) / 2;
			i++;
		}else{
			num = num/2;
			i++;
		}
	}
	printf("%d", i);
	return 0;
}
