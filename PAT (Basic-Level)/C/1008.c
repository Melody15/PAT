#include <stdio.h>

int main(void)
{
	int n, m, i, j, tem;
	scanf("%d %d", &n, &m);
	int Num[n];
	
	for(i = 0 ; i < n ; i++){
		scanf("%d",&Num[i]);
	}
	
	for(i=0;i<m;i++){      
	    tem = Num[n-1];      
	    for(j = n-1 ; j > 0 ; j--){       
	        Num[j] = Num[j-1];    
	    } 
	    Num[0]=tem;
    }
	
	for(i = 0 ; i < n; i++){
		printf("%d", Num[i]);
		if(i<n-1)
		printf(" ");
	}
	
    return 0;	
} 
