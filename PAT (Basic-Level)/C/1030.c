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

	for (int i = 0; count != N && i < N - count; i++) { // ��֪�������г��ȴﵽ������ʱ���˳�ȫ��ѭ��
        for (int j = i + count; j < N; j++) { // ����֤���н�β���ִ�i+count��ʼ
            if (j == N-1 || num[j+1] > (long long)num[i] * p) { 
                if (num[j] <= (long long)num[i] * p) { 
                // ����ʱ��ij��������������У����¸�j����������������Ҫ�󣬴�ʱ��ij��Ϊ���ڵ�ǰi����������������
                    temp = j - i + 1; // ���㵱ǰ���г���
                    count = (temp > count) ? temp : count; // ����֪�ĶԱȣ�ȡ�����һ��
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
