#include <stdio.h>

typedef struct {
	int data;
	int next;
}node;

int main()
{
	int i, j;
	int start, n, k, loc, pri_loc; 
	scanf("%d %d %d", &start, &n, &k);
	node list[100000];
	node tem[k];
	
	for(i = 0; i < n; i++){
		scanf("%d ", &loc);
		scanf("%d %d", &list[loc].data, &list[loc].next); 
	}
	j = n / k; //j为反转组数 
	loc = start;
	while(j > 0){
		pri_loc = loc;
		for(i = 0; i < k; i++){  
			tem[i] = list[loc];
			loc = list[loc].next;
		}
		
		for(i = 1; i < k - 1; i++){
			list[tem[i].next].next = tem[i-1].next;
        }
        list[tem[0].next].next = pri_loc;
		list[start].next = loc;        
        start = tem[k-2].next;
		j--;
	}
	
	loc = start;
	while(loc != -1){
		if(list[loc].next != -1)
			printf("%.5d %d %.5d\n", loc, list[loc].data, list[loc].next);
		else
			printf("%.5d %d %d\n", loc, list[loc].data, list[loc].next);
		
		loc = list[loc].next;
	}
	return 0;
}

