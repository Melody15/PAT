#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
需要考虑当resultRe/resultIm的值在-0.005~0时的情况，会出现-0.00
此外float不能满足精度
 */
int main(int argc, char const *argv[])
{
    double R1, P1, R2, P2;
    scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
    double Re1, Im1, Re2, Im2;
    Re1 = R1 * cos(P1);
    Im1 = R1 * sin(P1);
    Re2 = R2 * cos(P2);
    Im2 = R2 * sin(P2);
    double resultRe = Re1 * Re2 - Im1 * Im2;
    double resultIm = Re1 * Im2 + Re2 * Im1;
    if (resultRe + 0.005 >= 0 && resultRe < 0)
        printf("0.00");
    else
        printf("%.2f", resultRe);
    if (resultIm + 0.005 >= 0 && resultIm < 0)
        printf("+0.00i");
    else if(resultIm >= 0)
        printf("+%.2fi", resultIm);
    else
        printf("%.2fi", resultIm);
    return 0;
}