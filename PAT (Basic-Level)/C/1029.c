#include <stdio.h>
#include <string.h>

int main()
{
	char tar[80+1];     //��׼���� 
	char real[80+1];    //ʵ������ 
	char result[80];    //������ 
	scanf("%s", tar);
	scanf("%s", real);
	int i = 0, j = 0, k = 0;   //�ֱ�Ϊ�������������ָ�� 
	while(tar[i] != '\0'){    
		if(real[j] == tar[i]){ 
			i++, j++;
		}else{
			result[k] = tar[i];
			i++, k++;
		} 
	}
	for(int i = 0; i < k; i++){  //�����ڵ�Сд��ĸȫת��Ϊ��д 
		if(result[i] >= 'a' && result[i] <= 'z')
			result[i] = result[i] - 32;
	}
	for(int i = 0; i < k; i++){  //���ظ�����ĸ�����ֱ��Ϊ'!' 
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
