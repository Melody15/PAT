#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char f_date(char *s1, char *s2, int *count);
char f_data(char *s1, char *s2, int *count){
	char *p1, *p2;
	p1 = s1; p2 = s2;
	while(*p1 != *p2 || 'A' > *p1 || 'G' < *p1){
		p1++; p2++;
		(*count)++;
	}
	if(*p1 && *p2 && *p1 == *p2 && *p1 >= 'A' && *p1 <= 'G')
		return *p1; 
}

char f_hour(char *s1, char *s2, int *count);
char f_hour(char *s1, char *s2, int *count){
	char *p1, *p2;
	p1 = s1; p2 = s2;
	p1 = p1 + *count + 1;
	p2 = p2 + *count + 1;
	while(*p1 != *p2 || *p1 < '0' || (*p1 > '9' && *p1 < 'A') || *p1 > 'N'){
		p1++; p2++;
	}
	if(*p1 && *p2 && *p1 == *p2 && ((*p1 >= 'A' && *p1 <= 'N') || (*p1 >= '0' && *p1 <= '9')))
		return *p1; 
}

int f_min(char *s3, char *s4);
int f_min(char *s3, char *s4){
	int count = 0;
	char *p1, *p2;
	p1 = s3; p2 = s4;
	while(*p1 != *p2 || *p1 < 'a' || *p1 > 'z'){
		p1++; p2++;
		count++;
	}
	if(*p1 && *p2 && *p1 == *p2 && *p1 >= 'a' && *p1 <= 'z')
		return count;
} 

int main()
{
	int min;	
	char day, hour;
	int count = 0;
	char s1[60+1], s2[60+1], s3[60+1], s4[60+1];
	scanf("%s\n", s1);
	scanf("%s\n", s2);
	scanf("%s\n", s3);
	scanf("%s\n", s4);
	day = f_data(s1, s2, &count);
	switch(day)	{
		case 'A' : printf("MON "); break;
		case 'B' : printf("TUE "); break;
		case 'C' : printf("WED "); break;
		case 'D' : printf("THU "); break;
		case 'E' : printf("FRI "); break;
		case 'F' : printf("SAT "); break;
		case 'G' : printf("SUN "); break;
		default : break;
	}
//	printf("%d ", count);
	hour = f_hour(s1, s2, &count);
	if(hour >= '0' && hour <= '9'){
		printf("%.2d:", hour - 48);
	}else{
		printf("%d:", hour - 55);
	}

	min = f_min(s3, s4);
	printf("%.2d", min);
//	printf("%s %s %s %s", s1, s2, s3, s4);
	return 0;
}
