#include <stdio.h>
#include <time.h>

int main()
{
	long int C1, C2;
	scanf("%ld %ld", &C1, &C2);
	float time = (float) ((C2 - C1) / 100.0);
	int hour, min, second;
	int se_time;
	if((int)(time * 10) % 10 > 4){
		se_time = (int)time;
		se_time++;
	}else if((int)(time * 10) % 10 <= 4){
		se_time = (int)time;
	}
	hour = se_time / 3600;
	min = (se_time - 3600 * hour) / 60;
	second = se_time - 3600 * hour - min * 60;
	printf("%.2d:%.2d:%.2d", hour, min, second);
	return 0;
}
