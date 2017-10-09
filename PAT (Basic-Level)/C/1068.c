#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int isUnique(int **data, int M, int N, int judgeNum){
    int times = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if(data[i][j] == judgeNum)
                times++;
            if(times > 1)
                return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int M, N, TOL;
    scanf("%d %d %d", &M, &N, &TOL);
    //int data[N+2][M+2]; //直接定义的话无法直接将该二维数组作为参数传给isUnique
    int **data;
    data = (int**)malloc(sizeof(int*) * (N+2)); 
    for (int i = 0; i < N + 2; i++)
        data[i] = (int*)malloc(sizeof(int) * (M+2)); 

    int count = 0;
    int x, y, color;
    /*
    1.int isUnique[1<<24] = {0};在栈上直接分配会发生段错误
    2.int *isUnique; 
    isUnique = (int *)malloc(sizeof(int)*(1<<24));
    memset(isUnique, 0, sizeof(int) * (1<<24));在对上分配会超过题目限制内存大小
    */
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            scanf("%d", &data[i][j]);
            //isUnique[data[i][j]]++;
        }
    }
    for (int i = 0; i < N+2; i++)
        data[i][0] = 0;
    for (int i = 0; i < N+2; i++)
        data[i][M+1] = 0;
    for (int i = 0; i < M+2; i++)
        data[0][i] = 0;
    for (int i = 0; i < M+2; i++)
        data[N+1][i] = 0;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if(isUnique(data, M, N, data[i][j]) == 1){
                int d1 = abs(data[i][j] - data[i][j-1]);
                int d2 = abs(data[i][j] - data[i][j+1]);
                int d3 = abs(data[i][j] - data[i+1][j-1]);
                int d4 = abs(data[i][j] - data[i+1][j]);
                int d5 = abs(data[i][j] - data[i+1][j+1]);
                int d6 = abs(data[i][j] - data[i-1][j]);
                int d7 = abs(data[i][j] - data[i-1][j-1]);
                int d8 = abs(data[i][j] - data[i-1][j+1]);
                if(d1 > TOL && d2 > TOL && d3 > TOL && d4 > TOL && d5 > TOL && d6 > TOL && d7 > TOL && d8 > TOL){
                    count++;
                    x = j;
                    y = i;
                    color = data[i][j];
                }
            }
        }
    }
    if(count == 1)
        printf("(%d, %d): %d\n", x, y, color);
    else if(count == 0)
        printf("Not Exist\n");
    else
        printf("Not Unique\n");
    return 0;
}
