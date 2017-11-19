#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    char radixList[20], num1[20], num2[20];
    char ch;
    int radixListLength = 0, num1Length = 0, num2Length = 0;
    while((ch = getchar()) != '\n')
        radixList[radixListLength++] = ch;
    while((ch = getchar()) != '\n')
        num1[num1Length++] = ch;
    while((ch = getchar()) != '\n')
        num2[num2Length++] = ch;
    
    int minLength, maxLength, flat; //flat = 1��ʾnum1��λ��<=num2��λ��
    if(num1Length <= num2Length){
        minLength = num1Length;
        maxLength = num2Length;
        flat = 1;   
    }else{
        minLength = num2Length;
        maxLength = num1Length;
        flat = 2;
    }

    int radix;
    char result[20];
    int resultLength = 0;   //����ĳ���
    int advance = 0;    //��һλ�Ľ�λ
    for(int i = minLength; i > 0; i--){
        int add1, add2;     //��������
        radix = radixList[--radixListLength]-48;
        if(radix == 0)
        	radix += 10;
        add1 = num1[--num1Length]-48;
        add2 = num2[--num2Length]-48;
        if((add1 + add2 + advance) >= radix){
            result[resultLength++] = ((add1 + add2 + advance) % radix)+48;
            advance = 1;
        }else{
            result[resultLength++] = (add1 + add2 + advance)+48;
            advance = 0;
        }
    }
    for(int i = minLength; i < maxLength; i++){
        int add;
        if(flat == 1)
            add = num2[--num2Length]-48;
        else if(flat == 2)
            add = num1[--num1Length]-48;
        radix = radixList[--radixListLength]-48;
        if(radix == 0)
        	radix += 10;
        if((add + advance) >= radix){
            result[resultLength++] = ((add + advance) % radix)+48;
            advance = 1;
        }else{
            result[resultLength++] = (add + advance)+48;
            advance = 0;
        }
    }
    result[resultLength] = advance+48;  //��һλ�Ľ�λ
    flat = 0;   //����flat ��ʱ���ڱ��result�е�һ������ǰ��0�����
    for (int i = resultLength; i >= 0; i--){
    	if(result[i] == '0' && flat == 0)
    		continue;
    	else{
    		printf("%c", result[i]);
    		flat = 1;
		}
    }
    if(flat == 0)   //flat = 0��ʾû����������������Ϊ0
    	printf("0");
    return 0;
}
