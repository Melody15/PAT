#include <stdio.h>
int main()
{
    int n,p1,p2,d,count,i,j,s[100000];
    count=0;
    p1=1;
    p2=3;
    scanf("%d",&n);
    for(i = 2;i <= n;i++){
        s[i] = 1;
    }
    for(i = 2;i * i <= n;i++){//这里的判断条件改一下。。如果i*i>n。。下边的i*j肯定>n的。。
        if(s[i] == 1){
            for(j = i;i*j <= n;j++){//否则的话当i比较大的话i*j可能会超过int。。
            s[i*j] = 0;
            }
        }
    }
    for(i=5;i<=n;i++){
        if(s[i]==1){
            if((i-p2)==2){
                count++;
            }
            p1=p2;
            p2=i;
        }
    }
    printf("%d\n",count);
    return 0;
}
