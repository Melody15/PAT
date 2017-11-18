#include <stdio.h>
#include <stdlib.h>

int gcd(long long a, long long b);
void printNum(long long a, long long a1);

void add(long long a1, long long b1, long long a2, long long b2);
void sub(long long a1, long long b1, long long a2, long long b2);
void mul(long long a1, long long b1, long long a2, long long b2);
void divi(long long a1, long long b1, long long a2, long long b2);

int main(int argc, char const *argv[]){
    long long a1, b1, a2, b2;
    scanf("%lld/%lld", &a1, &b1);
    scanf("%lld/%lld", &a2, &b2);
    long long gcd1 = abs(gcd(a1, b1));
    long long gcd2 = abs(gcd(a2, b2));
    a1 /= gcd1;
    b1 /= gcd1;
    a2 /= gcd2;
    b2 /= gcd2;

    add(a1, b1, a2, b2);
    sub(a1, b1, a2, b2);
    mul(a1, b1, a2, b2);
    divi(a1, b1, a2, b2);
    return 0;
}

int gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a % b);
}

/*void printNum(long long a, long long b){ //????? 2 testpoints wrong ??
    long long integer = a/b; //integer could be + / -
    if(integer != 0){
        if(b == 1){ //only integer
            if(integer > 0)
                printf("%lld", integer);
            else if(integer < 0)
                printf("(%lld)", integer);
        }else if(b != 1){ 
            if(a > 0) //integer and fraction & integer > 1
                a = a%b;
            else if(a < 0)//integer and fraction & integer < -1
                a = abs(a)%b;
            if(integer > 0)
                printf("%lld %lld/%lld", integer, a, b);
            else if(integer < 0)
                printf("(%lld %lld/%lld)", integer, a, b);
        }
    }else if(integer == 0){ //a = 0 | |a| < b
        if(a == 0)
            printf("0");
        else if(a > 0)
            printf("%lld/%lld", a, b);
        else if(a < 0)
            printf("(%lld/%lld)", a, b);
    }
}*/
void printNum(long long a,long long b){
    long long integer = a/b;
    a = a%b;
    if(a < 0 || integer < 0)
        printf("(");
    if(a == 0)
        printf("%lld", integer);
    else if(integer != 0)
        printf("%lld %lld/%lld", integer, abs(a), abs(b));
    else
        printf("%lld/%lld",a,b);
    if(a < 0 || integer < 0)
        printf(")");
}

void add(long long a1, long long b1, long long a2, long long b2){
    printNum(a1, b1);
    printf(" + ");
    printNum(a2, b2);
    printf(" = ");
    long long a3, b3;
    a3 = a1*b2 + a2*b1;
    b3 = b1*b2;
    long long gcd3 = abs(gcd(a3, b3));
    a3 /= gcd3;
    b3 /= gcd3;
    printNum(a3, b3);
    printf("\n");
}
void sub(long long a1, long long b1, long long a2, long long b2){
    printNum(a1, b1);
    printf(" - ");
    printNum(a2, b2);
    printf(" = ");
    long long a3, b3;
    a3 = a1*b2 - a2*b1;
    b3 = b1*b2;
    long long gcd3 = abs(gcd(a3, b3));
    a3 /= gcd3;
    b3 /= gcd3;
    printNum(a3, b3);
    printf("\n");
}
void mul(long long a1, long long b1, long long a2, long long b2){
    printNum(a1, b1);
    printf(" * ");
    printNum(a2, b2);
    printf(" = ");
    long long a3, b3;
    a3 = a1*a2;
    b3 = b1*b2;
    long long gcd3 = abs(gcd(a3, b3));
    a3 /= gcd3;
    b3 /= gcd3;
    printNum(a3, b3);
    printf("\n");
}
void divi(long long a1, long long b1, long long a2, long long b2){
    printNum(a1, b1);
    printf(" / ");
    printNum(a2, b2);
    printf(" = ");
    if(a2 == 0){
        printf("Inf\n");
        return;
    }
    long long a3, b3;
    a3 = a1*b2;
    b3 = b1*a2;
    long long gcd3 = abs(gcd(a3, b3));
    a3 /= gcd3;
    b3 /= gcd3;
    if(b3 < 0){
        a3 = -a3;
        b3 = -b3;
    }
    printNum(a3, b3);
    printf("\n");
}
