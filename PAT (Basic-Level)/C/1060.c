#include <stdio.h>

void quicksort( int R[], int low, int high);
int partition(int R[], int low, int high); 


int main(int argc, char const *argv[]){
    int N;
    scanf("%d", &N);
    int day[N+1];
    for (int i = 1; i <= N; i++){   
        scanf("%d", &day[i]);
    }
    quicksort(day, 1, N);
    int Eddingtonnum = 0;
    int j = 1;
    while(Eddingtonnum <= N && day[j] > j){
        Eddingtonnum++;
        j++;
    }
    printf("%d", Eddingtonnum);
    return 0;
}

void quicksort( int R[], int low, int high){
    int idx;
    if(low < high){
        //调用划分过程将R一分为二， 以idx保存 “划分元”的位置
        idx = partition(R, low, high);
        quicksort(R, low, idx-1);      //对低端序列执行递归调用 
        quicksort(R, idx+1, high);     //对高端序列执行递归调用 
    }
}

int partition(int R[], int low, int high){
    R[0] = R[low];  //暂存划分元
    while(low < high){
        while((low < high) && (R[high] <= R[0]))
        high--;
        if(low < high){
            R[low] = R[high];
            low++;
        }
        while((low < high) && (R[low] >= R[0]))
        low++;
        if(low < high){
            R[high] = R[low];
            high--;
        }
    } 
    R[low] = R[0];
    return low;
}

/*分析：从下标1开始存储n天的公里数在数组a中，对n个数据从大到小排序，i表示了骑车的天数，那么满足a[i] > i的最大值即为所求
参考资料：https://www.liuchuo.net/archives/2480
*/