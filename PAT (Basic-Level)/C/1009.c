#include <stdio.h>
#include <stdlib.h>
#define N 80

int main()
{
	int i;
	struct word{
		char word[N+1];
	}*words[N];
	
	for(i=0;i<N;i++){
		words[i] = calloc(1, sizeof(struct word));
	}
	
    for(i=0;i<N;i++){
        scanf("%s", words[i]->word);
        if(getchar() == '\n')
        break;
    }
    
    for(i;i>=0;i--){
    	printf("%s",words[i]->word);
    	if(i>0)printf(" ");
	}
	return 0;
}
