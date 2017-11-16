#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quicksort(int R[], int low, int high);
int partition(int R[], int low, int high);

int main(int argc, char const *argv[]){
    //data input
    int N;
    scanf("%d", &N);
    int data[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &data[i]);
    quicksort(data, 0, N-1);

    //calculate row&col
    int row, col; // row >= col
    col = sqrt(N);
    while(N % col != 0)
        col--;
    row = N / col;
    
    int result[row][col];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            result[i][j] = 0;
    }

    int count = 0, i = 0, j = 0;
    while(count != N){
        for (; j < col; j++){  //move towards right
            if(result[i][j] == 0)
                result[i][j] = data[count++];
            else break;
        }
        j--; //back return
        i++; //next row
        for (; i < row; i++){
            if(result[i][j] == 0)
                result[i][j] = data[count++];
            else break;
        }
        i--;//back return
        j--;
        for (; j >= 0; j--){
            if(result[i][j] == 0)
                result[i][j] = data[count++];
            else break;
        }
        j++;
        i--;
        for (; i >= 0; i--){
            if(result[i][j] == 0)
                result[i][j] = data[count++];
            else break;
        }
        i++;
        j++;
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(j < col-1)
                printf("%d ", result[i][j]);
            else
                printf("%d", result[i][j]);
        }
        printf("\n");
    }
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
        while((low < high) && (R[high] <= temp))
            high--;
        if(low < high){
            R[low] = R[high];
            low++;
        }
        while((low < high) && (R[low] >= temp))
            low++;
        if(low < high){
            R[high] = R[low];
            high--;
        }
    } 
    R[low] = temp;
    return low;
}
