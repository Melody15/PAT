#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){ return *(int*)a - *(int*)b;}

int main(int argc, char const *argv[]){
    int N;
    scanf("%d", &N);
    int origin[N];
    int halfOutput[N];
    int flat = 0; // 0 --- insertion-sort & 1 --- merge-sort
    for (int i = 0; i < N; i++)
        scanf("%d", &origin[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &halfOutput[i]);
    
    /*The feature of insertion sort is that the former elements are in order and the latter elements were not be changed. val 'index' is index of the last element which was in order.*/
    int index;  
    for (int i = 0; i < N; i++){
        if(halfOutput[i] <= halfOutput[i+1])
            index = i+1;
        else break;
    }
    for (int i = index+1; i < N; i++){
        if(halfOutput[i] != origin[i]){
            flat = 1;
            break;
        }
    }

    if(flat == 0){
        printf("Insertion Sort\n");
        qsort(origin, index+2, sizeof(int), cmp);

    }else if(flat == 1){
        printf("Merge Sort\n");
        int k = 1;
        int notEqual = 1;
        while(notEqual){
            notEqual = 0;
            for (int i = 0; i < N; i++){
                if(origin[i] != halfOutput[i]){
                    notEqual = 1;
                    break;
                }
            }
            
            k *= 2;
            for(int i = 0; i < N / k; ++i){
                qsort(origin + i*k, k, sizeof(int), cmp);
            }
            qsort(origin + (N/k)*k, N%k, sizeof(int), cmp); // sort the remain elements(the remain group whose elements number is less than 2^k)
        }
    }

    for (int i = 0; i < N; i++){
        if(i == 0)
            printf("%d", origin[i]);
        else
            printf(" %d", origin[i]);
    }
    return 0;
}
