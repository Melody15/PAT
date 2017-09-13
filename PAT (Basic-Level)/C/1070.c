#include <stdio.h>

void quicksort(int R[], int low, int high);
int partition(int R[], int low, int high); 

int main(int argc, char const *argv[]){
    int N;
    scanf("%d", &N);
    int ropes[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &ropes[i]);
    }
    quicksort(ropes, 0, N-1);

    int result = ropes[0];
    for (int i = 1; i < N; i++){
        result = (result + ropes[i]) / 2;
    }
    printf("%d", result);
    return 0;
}

void quicksort(int R[], int low, int high){
    int idx;
    if(low < high){
        idx = partition(R, low, high);
        quicksort(R, low, idx-1);      
        quicksort(R, idx+1, high);     
    }
}
int partition(int R[], int low, int high){
    int temp = R[low];  
    while(low < high){
        while((low < high) && (R[high] >= temp))
        high--;
        if(low < high){
            R[low] = R[high];
            low++;
        }
        while((low < high) && (R[low] <= temp))
        low++;
        if(low < high){
            R[high] = R[low];
            high--;
        }
    } 
    R[low] = temp;
    return low;
}

/*让长的绳子对折的次数尽可能的少，所以绳子越长加入的越晚即可，在开始对折前先进行一次排序*/