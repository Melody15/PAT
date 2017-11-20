#include <stdio.h>

int main(int argc, char const *argv[]){
    int firstAddress, N, K;
    int data[100000], nextAddress[100000];
    scanf("%d %d %d", &firstAddress, &N, &K);
    int count1 = 0, count2 = 0, count3 = 0;
    int address;
    for (int i = 0; i < N; i++){
        scanf("%d", &address);
        scanf("%d %d", &data[address], &nextAddress[address]);
    }

    int result1Address[N], result2Address[N], result3Address[N];
    address = firstAddress;
    while(address != -1){
        if(data[address] < 0)
            result1Address[count1++] = address;
        else if(data[address] >= 0 && data[address] <= K)
            result2Address[count2++] = address;
        else
            result3Address[count3++] = address;

        address = nextAddress[address];
    }
    
    if(count2 == 0 && count3 == 0){
        for (int i = 0; i < count1 - 1; i++)
        printf("%05d %d %05d\n", result1Address[i], data[result1Address[i]], result1Address[i+1]);
        printf("%05d %d -1\n", result1Address[count1-1], data[result1Address[count1-1]]);
    }else if(count2 != 0 && count3 == 0){
        result1Address[count1] = result2Address[0];
        for (int i = 0; i < count1; i++)
        printf("%05d %d %05d\n", result1Address[i], data[result1Address[i]], result1Address[i+1]);
        for (int i = 0; i < count2 - 1; i++)
        printf("%05d %d %05d\n", result2Address[i], data[result2Address[i]], result2Address[i+1]);
        printf("%05d %d -1\n", result2Address[count2-1], data[result2Address[count2-1]]);
    }else if(count1 != 0 && count2 == 0 && count3 != 0){
        result1Address[count1] = result3Address[0];
        for (int i = 0; i < count1; i++)
        printf("%05d %d %05d\n", result1Address[i], data[result1Address[i]], result1Address[i+1]);
        for (int i = 0; i < count3 - 1; i++)
        printf("%05d %d %05d\n", result3Address[i], data[result3Address[i]], result3Address[i+1]);
        printf("%05d %d -1\n", result3Address[count3-1], data[result3Address[count3-1]]);
    }else{
        result1Address[count1] = result2Address[0];
        result2Address[count2] = result3Address[0];
        for (int i = 0; i < count1; i++)
        printf("%05d %d %05d\n", result1Address[i], data[result1Address[i]], result1Address[i+1]);
        for (int i = 0; i < count2; i++)
        printf("%05d %d %05d\n", result2Address[i], data[result2Address[i]], result2Address[i+1]);
        for (int i = 0; i < count3 - 1; i++)
        printf("%05d %d %05d\n", result3Address[i], data[result3Address[i]], result3Address[i+1]);
        printf("%05d %d -1\n", result3Address[count3-1], data[result3Address[count3-1]]);
    }
    return 0;
}