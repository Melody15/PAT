#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(int argc, char const *argv[]){
    int N, M, origin, target;
    scanf("%d %d %d %d", &N, &M, &origin, &target);
    int rescueTempNum[N]; //救援队数量
    int sumTempNum[N];  //从出发点到i的最大总救援队
    int pathNum[N];     //从出发点到i的最短路径的条数
    //int path[N]; //记录前驱结点
    int dist[N]; //记录最短路径

    int arc[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(i == j)
                arc[i][j] = 0;
            else
                arc[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < N; i++){
        scanf("%d", &rescueTempNum[i]);
    }
    sumTempNum[origin] = rescueTempNum[origin];
    pathNum[origin] = 1; //不加的话test1错误

    for (int i = 0; i < M; i++){
        int m, n;
        scanf("%d %d", &m, &n);
        scanf("%d", &arc[m][n]);
        arc[n][m] = arc[m][n];
    }

    int S[N]; 
    for (int i = 0; i < N; i++)
        S[i] = 0;

    S[origin] = 1; // 将v0加入到集合S中
    for(int i = 0; i < N; i++) {
        if(i != origin){
            dist[i] = arc[origin][i]; // v0到其他顶点的当前最短距离
            if(dist[i] < INT_MAX){
                //path[i] = origin; // 记录前驱
                pathNum[i] = 1;
                sumTempNum[i] = sumTempNum[origin] + rescueTempNum[i];
            }else{
                //path[i] = -1;
                pathNum[i] = 0;  //这两行注释掉也没关系
                sumTempNum[i] = 0;
            }
        }  
    }

    for(int i = 0; i < N; ++i) {
        if(i != origin){
            int min = INT_MAX, v = -1;
            for(int k = 0; k < N; k++){ // 找出最小的dist[k]
                if(S[k] == 0 && dist[k] < min) {
                    v = k; 
                    min = dist[k]; 
                } 
            }
            if(v == -1) 
                break; // 已无顶点可加入S中
            S[v] = 1; // 将顶点v并入集合S
            for(int k = 0; k < N; k++){
                if(S[k] == 0 && (arc[v][k] != INT_MAX)){
                    if(min < (dist[k] - arc[v][k])){
                        dist[k] = min + arc[v][k]; 
                        //path[k] = v; 
                        pathNum[k] = pathNum[v];
                        sumTempNum[k] = sumTempNum[v] + rescueTempNum[k];
                    }else if(min == (dist[k] - arc[v][k])){
                        pathNum[k] = pathNum[k] + pathNum[v];
                        if(sumTempNum[v] + rescueTempNum[k] > sumTempNum[k])
                            sumTempNum[k] = sumTempNum[v] + rescueTempNum[k];
                    }
                }
            }
        }
    }
    printf("%d %d", pathNum[target], sumTempNum[target]);
    return 0;
}