#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int p_num = 0;
    int t_num = 0;
    char patset[100000];
    char ch;
    int i = 0;
    int sum = 0;
    while((ch = getchar()) != '\n'){
        patset[i] = ch; i++;
        if(ch == 'T') t_num++;
    }
    for(int j = 0; j < i; j++){
        if(patset[j] == 'P') p_num++;
        if(patset[j] == 'T') t_num--;
        if(patset[j] == 'A'){
            sum = (sum +((p_num * t_num) % 1000000007)) % 1000000007; //key step
        }
    }
    printf("%d", sum);
    return 0;
}

/*reference:
https://www.liuchuo.net/archives/573
分析：要想知道构成多少个PAT，那么遍历字符串后对于每一A，它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数。然后把对于每一个A的结果相加即可~~辣么就简单啦，只需要先遍历字符串数一数有多少个T~~然后每遇到一个T呢~countt–;每遇到一个P呢，countp++;然后一遇到字母A呢就countt * countp~~~把这个结果累加到result中~~~~最后输出结果就好啦~~对了别忘记要对10000000007取余哦~~~~
*/