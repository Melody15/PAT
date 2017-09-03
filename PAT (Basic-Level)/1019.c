#include <stdio.h>
#include <stdlib.h>

void change_num(int num, char num_sort[]);
void quicksort1(char R[], int low, int high);
int partition1(char R[], int low, int high); 
void quicksort2(char R[], int low, int high);
int partition2(char R[], int low, int high); 

int main()
{
	int num, tem;
	char num_sort[4];
	scanf("%d", &num);
	do{
		change_num(num, num_sort);
		if(num_sort[0] == num_sort[1] && num_sort[1] == num_sort[2] && num_sort[2] == num_sort[3]){
			printf("%.4d - %.4d = 0000\n", num, num);
			break;
		} 
		quicksort2(num_sort, 0, 3);
		tem = atoi(num_sort);
		printf("%.4d - ", tem);
		quicksort1(num_sort, 0, 3);
		printf("%.4d = ", atoi(num_sort));
		num = tem - atoi(num_sort);
		printf("%.4d\n", num);
	}while(num != 6174);
	return 0;
} 

void change_num(int num, char num_sort[]){
	int i, j;
	i = 3;
	if(num >= 1000){
		while(num != 0){
			j = num%10;
			num_sort[i] = j + 48;
			num = num/10;
			i--;
		}
	}else if(num >= 100 && num < 1000){
		num_sort[0] = '0';
		while(num != 0){
			j = num%10;
			num_sort[i] = j + 48;
			num = num/10;
			i--;
		}
	}else if(num >= 10 && num < 100){
		num_sort[0] = '0'; num_sort[1] = '0';
		while(num != 0){
			j = num%10;
			num_sort[i] = j + 48;
			num = num/10;
			i--;
		}
	}else if(num >0 && num < 10){
		num_sort[0] = '0'; num_sort[1] = '0'; num_sort[2] = '0';
		num_sort[i] = num + 48;
	}
}
void quicksort1(char R[], int low, int high){
	int idx;
	if(low < high){
		//调用划分过程将R一分为二， 以idx保存 “划分元”的位置
		idx = partition1(R, low, high);
		quicksort1(R, low, idx-1);      //对低端序列执行递归调用 
		quicksort1(R, idx+1, high);     //对高端序列执行递归调用 
	}
}
int partition1(char R[], int low, int high){
	char tem = R[low];
	while(low < high){
		while((low < high) && (R[high] >= tem))
		high--;
		if(low < high){
			R[low] = R[high];
			low++;
		}
		while((low < high) && (R[low] <= tem))
		low++;
		if(low < high){
			R[high] = R[low];
			high--;
		}
	} 
	R[low] = tem;
	return low;
}
void quicksort2(char R[], int low, int high){
	int idx;
	if(low < high){
		//调用划分过程将R一分为二， 以idx保存 “划分元”的位置
		idx = partition2(R, low, high);
		quicksort2(R, low, idx-1);      //对低端序列执行递归调用 
		quicksort2(R, idx+1, high);     //对高端序列执行递归调用 
	}
}
int partition2(char R[], int low, int high){
	char tem = R[low];
	while(low < high){
		while((low < high) && (R[high] <= tem))
		high--;
		if(low < high){
			R[low] = R[high];
			low++;
		}
		while((low < high) && (R[low] >= tem))
		low++;
		if(low < high){
			R[high] = R[low];
			high--;
		}
	} 
	R[low] = tem;
	return low;
}
