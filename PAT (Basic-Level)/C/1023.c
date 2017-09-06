#include <stdio.h>

int main()
{
	int i;
	int num_rec[10];
	for(i = 0; i < 10; i++){
		scanf("%d", &num_rec[i]);
	}
/*	for(i = 0; i < 10; i++){
		printf("%d ", num_rec[i]);
	}*/
	i = 0;
	while(i < 9){
		i++;
		if(num_rec[i] != 0){
			printf("%d", i);
			num_rec[i]--;
			break;
		}
	}
	i = -1;
	while(i < 9){
		i++;
		while(num_rec[i] != 0){
			printf("%d", i);
			num_rec[i]--;
		}
	}
	return 0;
}
