#include <stdio.h>
#include <stdlib.h>

typedef struct{
	double amount;
	double sum_price;
	double single_price;
}moke_inf;

void quick_sort( moke_inf moke[], int low, int high);
void quick_sort( moke_inf moke[], int low, int high){
	int idx;
	if(low < high){
		//调用划分过程将R一分为二， 以idx保存 “划分元”的位置
		idx = partition(moke, low, high);
		quick_sort(moke, low, idx-1);      //对低端序列执行递归调用 
		quick_sort(moke, idx+1, high);     //对高端序列执行递归调用 
	}
}

int partition(moke_inf moke[], int low, int high); 
int partition(moke_inf moke[], int low, int high){
	moke_inf tem;
	tem = moke[low];  //暂存划分元
	while(low < high){
		while((low < high) && (moke[high].single_price <= tem.single_price))
		high--;
		if(low < high){
			moke[low] = moke[high];
			low++;
		}
		while((low < high) && (moke[low].single_price >= tem.single_price))
		low++;
		if(low < high){
			moke[high] = moke[low];
			high--;
		}
	} 
	moke[low] = tem;
	return low;
}

int main()
{
	int n, sum_need;
	double sale = 0;
	scanf("%d %d", &n, &sum_need);
	moke_inf moke[n];
	int i;
	for(i = 0; i < n; i++){
		scanf("%lf", &moke[i].amount);
	}
	
	for(i = 0; i < n; i++){
		scanf("%lf", &moke[i].sum_price);
		moke[i].single_price = moke[i].sum_price / moke[i].amount;
	}
	quick_sort(moke, 0, n-1);

	i = 0;
	while(sum_need > 0){
		if(sum_need >= moke[i].amount){ //sum_need > moke[i].amount时 测试点1超时，改为>=后测试点3出错 将结构体的数据类型从float改为double可全部通过
			sale += moke[i].sum_price;
			sum_need -= moke[i].amount;
			i++;
		}else if(sum_need > 0 && sum_need < moke[i].amount){
			sale += (moke[i].single_price * sum_need);
			sum_need = 0; 
		}
	}
	printf("%.2f", sale);
	return 0;
} 
