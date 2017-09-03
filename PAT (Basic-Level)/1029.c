#include <stdio.h>
#include <string.h>

int main()
{
	char tar[80+1];     //标准输入 
	char real[80+1];    //实际输入 
	char result[80];    //储存结果 
	scanf("%s", tar);
	scanf("%s", real);
	int i = 0, j = 0, k = 0;   //分别为以上三个数组的指针 
	while(tar[i] != '\0'){    
		if(real[j] == tar[i]){ 
			i++, j++;
		}else{
			result[k] = tar[i];
			i++, k++;
		} 
	}
	for(int i = 0; i < k; i++){  //将存在的小写字母全转换为大写 
		if(result[i] >= 'a' && result[i] <= 'z')
			result[i] = result[i] - 32;
	}
	for(int i = 0; i < k; i++){  //将重复的字母或数字标记为'!' 
		if(result[i] != '!'){
			for(int j = i + 1; j < k; j++){
				if(result[j] == result[i])
					result[j] = '!';
			}
		}
	}
	for(int i = 0; i < k; i++){
		if(result[i] != '!')
			printf("%c", result[i]);
	}
	return 0;
}
