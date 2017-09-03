#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define N 10


int main(void)
{
	struct children {
	char Name[N+1];
	char Number[N+1];
	int Grade;
    } *Children[MAX];

	int n, i, highest, poorest, h = 0, p = 0;
	scanf("%d", &n);
	
	for(i = 0 ; i < n ; i++){
		Children[i] = (struct children *)calloc(1,sizeof(struct children));
	}
	
	for(i = 0 ; i < n ; i++){
		scanf("%s %s %d", Children[i]->Name, Children[i]->Number, &Children[i]->Grade);
	}
	
	highest = Children[0]->Grade;
	poorest = Children[0]->Grade;
	for(i = 1; i < n; i++){
		if (Children[i]->Grade > highest) {
			highest = Children[i]->Grade;
			h = i;
		}
		if (Children[i]->Grade < poorest) {
			poorest = Children[i]->Grade;
			p = i;
		}
	}
	printf("%s ", Children[h]->Name);
	printf("%s\n", Children[h]->Number);
	printf("%s ", Children[p]->Name);
	printf("%s", Children[p]->Number);
	
	return 0;
}
