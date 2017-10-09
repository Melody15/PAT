#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(int argc, char const *argv[]){
    int N;
    scanf("%d", &N);
    int data[N];
    int sortArray[N];
    int result[N];
    int count = 0, max = 0;
    for (int i = 0; i < N; i++){
        scanf("%d", &data[i]);
        sortArray[i] = data[i];
    }
    qsort(sortArray, N, sizeof(int), cmp);

    for (int i = 0; i < N; i++){
        if(max < data[i])
            max = data[i];
        if(data[i] == max && data[i] == sortArray[i])
            result[count++] = data[i];
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++){
        if(i == 0)
            printf("%d", result[i]);
        else
            printf(" %d", result[i]);
    }
    printf("\n");
    return 0;
}

/*主元的位置与排完序后该元素所在位置相同，那么再满足它是它之前所有元素中最大的一个，就可以断定它是主元
reference: http://blog.csdn.net/gq_bob/article/details/49520161
*/