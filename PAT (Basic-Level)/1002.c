#include <stdio.h>
int main(void)
{
	char Num[100+1], ch;
	int sum = 0, tem_1, tem[10], j = 0, i = 0 ;
	
	
	while((ch = getchar()) != '\n'){
	Num[j] = ch;
	j++;
    }
    j--;
    for(j; j >= 0 ; j--){
    	sum += Num[j] - '0';
	}
	
	while(sum != 0){
		tem[i] = sum % 10;
		i++;
		sum = sum / 10;
	}
	i--;
	for( i ; i >= 0 ; i-- ){
		switch (tem[i]) {
			case 1 : printf("yi"); 
			break;
			case 2 : printf("er");
			break;
			case 3 : printf("san");
			break;
			case 4 : printf("si");
			break;
			case 5 : printf("wu");
			break;
			case 6 : printf("liu");
			break;
			case 7 : printf("qi");
			break;
			case 8 : printf("ba");
			break;
			case 9 : printf("jiu");
			break;
			default : printf("ling");
			break;
		}
		if (i > 0){
			printf(" ");
		}
	}
	return 0;
}
