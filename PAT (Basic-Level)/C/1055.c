#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentInfo{
    char name[10];
    int height;
}student;

int qsortCmp(const void *a, const void *b){ //qsort's compare function
    student *c=(student*)a;  
    student *d=(student*)b;  
    if(c->height == d->height)
        return (strcmp(c->name,d->name));
    else
        return d->height - c->height;
}  

void printrow(student s[], int num){
    for(int i = num / 2 * 2 - 1; i > 0; i -= 2)     /* on the left */
        printf("%s ", s[i].name);
    for(int i = 0; i < num; i += 2)                 /* on the right */
        printf("%s%c", s[i].name, i + 2 < num ? ' ' : '\n');
}

int main(int argc, char const *argv[]){
    int N, K;
    scanf("%d %d", &N, &K);
    student studentInPhoto[N];
    
    for (int i = 0; i < N; i++){
        scanf("%s %d", studentInPhoto[i].name, &studentInPhoto[i].height);
    }
    qsort(studentInPhoto, N, sizeof(student), qsortCmp);
    int rowsNum = N / K;
    int lastRowNum = N - rowsNum * (K - 1);
    student *p = studentInPhoto;
    printrow(p, lastRowNum);
    for(p += lastRowNum; p < studentInPhoto + N; p += rowsNum)
        printrow(p, rowsNum);
    return 0;
}
/*每一行从左开始先倒序输出奇数位的人名，再顺序输出偶数位的人名。这里按照已排好的顺序从0计数。e.g. 输出7个人名就是5 3 1 0 2 4 6
reference: http://blog.csdn.net/Oliver__Lew/article/details/72512636
*/