#include <stdio.h>
#include <stdlib.h>
#define N 15

typedef struct{
	int top, len;
	int sta[N];
}TStack, *PStack;

void push_sta(PStack Pstack, int data);
void push_sta(PStack Pstack, int data){
	Pstack->sta[Pstack->top++] = data;
	Pstack->len++;
}

int pop_sta(PStack Pstack);
int pop_sta(PStack Pstack){
	int data;
	Pstack->top--;
	data = Pstack->sta[Pstack->top];
	Pstack->len--;
	return data;
}

int main()
{
	long int a, b, sum;
	int d, tem;
	scanf("%ld %ld %d", &a, &b, &d);
	sum = a + b;
	PStack Pstack;
	Pstack = (PStack)malloc(sizeof(TStack));
	if(!Pstack){
		printf("ÄÚ´æ·ÖÅäÊ§°Ü.\n"); exit(1);
	}
	Pstack->top = 0; Pstack->len =  0;
	while(sum != 0){
		tem = sum % d;
		sum = sum / d;
		push_sta(Pstack, tem);
	}
	while(Pstack->len != 0){
		printf("%d", pop_sta(Pstack));
	}
	if(a==0 && b==0){
		printf("0");
	}
	
	return 0;
}
