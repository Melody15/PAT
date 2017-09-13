#include <stdio.h>

/*首先将地址作为索引下标index，分别存储数据与next地址
再按照初始顺序将地址存入一个数组，最后对该数组按要求进行排序即可
注意：不一定所有的输入的结点都是有用的，使用计数器
*/

int main(int argc, char const *argv[]){
    int firstAddress, N, K;
    int data[100000], nextAddress[100000];
    scanf("%d %d %d", &firstAddress, &N, &K);
    int tempAddress[N], resultAddress[N];
    int address;
    int sum = 0;
    for (int i = 0; i < N; i++){
        scanf("%d", &address);
        scanf("%d %d", &data[address], &nextAddress[address]);
    }
    address = firstAddress;
    while(address != -1){
        tempAddress[sum] = address;
        resultAddress[sum++] = address;
        address = nextAddress[address];
    }

    for(int i = 0; i < (sum - sum % K); i++){
        resultAddress[i] = tempAddress[(i/K)*K + K-i%K - 1]; //method
    }
    for (int i = 0; i < sum - 1; i++){
        printf("%05d %d %05d\n", resultAddress[i], data[resultAddress[i]], resultAddress[i+1]);
    }
    printf("%05d %d -1\n", resultAddress[sum-1], data[resultAddress[sum-1]]);
    return 0;
}