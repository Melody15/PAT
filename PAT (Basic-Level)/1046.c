#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int A_y;
	int A_a;
	int B_y;
	int B_a;
}game;

int main()
{
	int n;
	scanf("%d", &n);
	game *games;
	games = (game *)malloc(sizeof(game)*n);
	if(!games){
		printf("ÄÚ´æ·ÖÅäÊ§°Ü.\n");
	}
	int i;
	for(i = 0; i < n; i++){
		scanf("%d %d %d %d", &games[i].A_y, &games[i].A_a, &games[i].B_y, &games[i].B_a);
	}
	int A_l = 0, B_l = 0;
	int sum_y;
	for(i = 0; i < n; i++){
		sum_y = games[i].A_y + games[i].B_y;
		if(sum_y == games[i].A_a && sum_y != games[i].B_a)
			B_l++;
		else if(sum_y == games[i].B_a && sum_y != games[i].A_a)
			A_l++;
	}
	
	printf("%d %d", A_l, B_l);
	return 0;
}
