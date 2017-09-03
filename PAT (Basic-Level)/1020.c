#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float amount;
	float sum_price;
	float single_price;
}moke_inf;

typedef moke_inf ElementType;
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

/*void Swap(ElementType *a,ElementType *b)
{ 
	ElementType tem;
	tem=*a; *a=*b; *b=tem;
}

void Quick_Sort( ElementType A[], int N );

void Quicksort( ElementType A[], int Left, int Right);

ElementType Median3(ElementType A[], int Left, int Right);
*/
int main()
{
	int n, sum_need;
	float sale = 0;
	scanf("%d %d", &n, &sum_need);
	moke_inf moke[n];
	int i;
	for(i = 0; i < n; i++){
		scanf("%f", &moke[i].amount);
	}
	
	for(i = 0; i < n; i++){
		scanf("%f", &moke[i].sum_price);
		moke[i].single_price = moke[i].sum_price / moke[i].amount;
	}
	quick_sort(moke, 0, n-1);
//	Quick_Sort(moke, n);
	i = 0;
	while(sum_need > 0){
		if(sum_need > moke[i].amount){
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
/*void Quick_Sort( ElementType A[], int N ){
	Quicksort( A, 0, N-1);
}
void Quicksort( ElementType A[], int Left, int Right){
	if(Right - Left < 2) return; 
	int i, j;
	ElementType Pivot;
	Pivot = Median3(A, Left, Right);
	i = Left + 1; j = Right;
	for( ; ; ){
		while(A[++i].single_price > Pivot.single_price) { }
		while(A[--j].single_price < Pivot.single_price) { }
		if(i < j)
			Swap(&A[i], &A[j]);
		else break;
	}
	Swap(&A[j], &A[Left + 1]);
	Quicksort(A, Left, i-1);
	Quicksort(A, i+1, Right);

}
ElementType Median3(ElementType A[], int Left, int Right){
	int Center = (Left + Right) / 2;
	if(A[Left].single_price < A[Center].single_price)
		Swap(&A[Left], &A[Center]);
	if(A[Left].single_price < A[Right].single_price)
		Swap(&A[Left], &A[Right]);
	if(A[Center].single_price < A[Right].single_price)
		Swap(&A[Center], &A[Right]);
	//A[Left] >= A[Center] >= A[Right]
	Swap(&A[Center], &A[Left+1]); //将pivot藏到左边
	//只需考虑A[Left+2]...A[Right-1]
	return A[Center]; 
}*/

