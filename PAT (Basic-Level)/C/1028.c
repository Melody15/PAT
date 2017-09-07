#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef struct{
	char name[6];
	int year, day, month;
}birthday;

int main()
{
	int n;
	scanf("%d", &n);
	int avail = 0;
	birthday min, max;
	min.year = min.day = min.month = INT_MAX;
	max.year = min.day = min.month = INT_MIN;
	int t_year, t_day, t_month;
	char tem_name[6];
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d/%d/%d", tem_name, &t_year, &t_month, &t_day);
		if((t_year < 2014 && t_year > 1814) || (t_year == 2014 && t_month < 9) || (t_year == 1814 && t_month > 9) || (t_year == 2014 && t_month == 9 && t_day <= 6) || 
		(t_year == 1814 && t_month == 9 && t_day >= 6)){
			if(t_year < min.year || t_year == min.year && t_month < min.month || t_year == min.year && t_month == min.month && t_day < min.day){
				min.year = t_year; min.month = t_month; min.day = t_day;
				strcpy(min.name, tem_name);
			}
			if(t_year > max.year || t_year == max.year && t_month > max.month || t_year == max.year && t_month == max.month && t_day > max.day){
				max.year = t_year; max.month = t_month; max.day = t_day;
				strcpy(max.name, tem_name);
			}
			avail++;			
		}
	}
	if(avail)    //判断是否为没有合理结果的情况 
		printf("%d %s %s", avail, min.name, max.name);
	else
		printf("%d", avail);
	return 0;
}
