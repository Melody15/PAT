#include <stdio.h>

int main(int argc, char const *argv[]){
    int cp[100000];
    for (int i = 0; i < 100000; i++)
        cp[i] = -2;
    
    int N, M, count = 0;
    scanf("%d", &N);
    int left, right, temp;
    for (int i = 0; i < N; i++){
        scanf("%d %d", &left, &right);
        cp[left] = right;
        cp[right] = left;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++){
        scanf("%d", &temp);
        if(cp[temp] != -2)
            cp[temp] = -2;
        else{
            cp[temp] = -1;
            count++;
        }  
    }
    for (int i = 0; i < 100000; i++){
        if(cp[i] >= 0 && cp[cp[i]] == -2){
            cp[cp[i]] = -1;
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < 100000; i++){
        if(cp[i] == -1){
            if(count > 1){
                printf("%05d ", i);
                count--;
            }
            else
                printf("%05d", i);
        }
    }
    return 0;
}