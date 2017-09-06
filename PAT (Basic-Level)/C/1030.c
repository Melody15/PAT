#include <stdio.h>

void quick_sort(int a[], int low, int high);
int partition(int a[], int low, int high);


int main()
{
	int N;
	int p;
	scanf("%d", &N);
	scanf("%d", &p);
	
	int num[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}
	quick_sort(num, 0, N-1);
	int count = 0, temp = 0;
	int j = 0;

	for (int i = 0; count != N && i < N - count; i++) { // 已知完美数列长度达到最大可能时，退出全部循环
        for (int j = i + count; j < N; j++) { // 待验证数列结尾部分从i+count开始
            if (j == N-1 || num[j+1] > (long long)num[i] * p) { 
                if (num[j] <= (long long)num[i] * p) { 
                // 当此时的ij组合满足完美数列，但下个j，不满足完美数列要求，此时的ij对为对于当前i的最大可能完美数列
                    temp = j - i + 1; // 计算当前数列长度
                    count = (temp > count) ? temp : count; // 跟已知的对比，取更大的一个
                }
                break;
            }
        }
    }
	printf("%d\n", count);
	return 0;
}

void quick_sort(int a[], int low, int high){
	int idx;
	if(low < high){
		idx = partition(a, low ,high);
		quick_sort(a, low, idx - 1);
		quick_sort(a, idx + 1, high);
	}
}

int partition(int a[], int low, int high){
	int tem = a[low];
	while(low < high){
		while(low < high && a[high] >= tem)
			high--;
		if(low < high){
			a[low] = a[high];
			low++;
		}
		while(low < high && a[low] <= tem)
			low++;
		if(low < high){
			a[high] = a[low];
			high--;
		}
	}
	a[low] = tem;
	return low;
}
