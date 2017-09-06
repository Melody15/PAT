#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define id_lenth 18
#define max 100
int main()
{
    int N;
    int passflat = 1;
    int allnumflat;
    int count = 0;
    int znum;
    char checkchar;
    char id[id_lenth];
    int weight[id_lenth-1] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char dict_M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    char errorid[max][id_lenth];
    int errnum = 0;

    scanf("%d", &N);
    while(count < N){
        getchar(); //clean the enter
        allnumflat = 1;
        for(int i = 0; i < id_lenth; i++){
            id[i] = getchar();
            if(i < id_lenth - 1){ 
        		if(id[i] < '0' || id[i] > '9'){
          		allnumflat = 0;
          	  	} 
            }
        }
        if(allnumflat == 1){
            int sum = 0;
            for(int i = 0; i < id_lenth-1; i++){
                sum += (id[i] - '0') * weight[i];
            }
            znum = sum % 11;
            checkchar = dict_M[znum];
            if(checkchar != id[id_lenth-1]){
                passflat = 0;
                for(int i = 0; i < id_lenth; i++){
                    errorid[errnum][i] = id[i];
                }
                errnum++;
            }
        }else if(allnumflat == 0){
            for(int i = 0; i < id_lenth; i++){
                errorid[errnum][i] = id[i]; 
            }
            errnum++;
        }
        count++;
    }
    if(passflat == 1){
        printf("All passed");
    }
    else{
        for(int i = 0; i < errnum; i++){
        	for(int j = 0; j < id_lenth; j++){
            printf("%c",errorid[i][j]);
	        }
	        printf("\n");
        }
    }
    return 0;
}
