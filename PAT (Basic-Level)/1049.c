#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    double num_list[N];
    double sum = 0.0;
    for(int i = 0; i < N; i++){
        scanf("%lf", &num_list[i]);
    }
    for(int i = 0; i < N; i++){
        sum += num_list[i] * (N - i) * (i + 1);
    }
    printf("%.2f", sum);
    return 0;
}

/*值得注意的是：

sum += a[i] * (N - i) * (i + 1);
与

sum += (N - i) * (i + 1) * a[i];
这两种写法有所差距。第一种写法，三次运算每次都是 double 型，第二种写法，第一次运算结果是 int 型，有可能出现溢出。当 i = N/2 时，(N - i) * (i + 1) 的值最大，超过了 int 型所能表示的范围。你可以对第二种写法进行强制类型转换（转换成 long long int 或者 double 都可，推荐 long long int，这样至少在精度上少了一次损失），或者写成第一种那样，利用 C 语言的自动类型转换。
http://www.cnblogs.com/andywenzhi/p/5837751.html

*/