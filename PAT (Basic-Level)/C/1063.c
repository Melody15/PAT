#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int a, b;
    double radius = 0;
    double temp = 0;
    for (int i = 0; i < N; ++i)
    {
        scanf("\n%d %d", &a, &b);
        temp = sqrt(a*a + b*b);
        if(temp > radius){
            radius = temp;
        }
    }
    printf("%.2f", radius);
    return 0;
}