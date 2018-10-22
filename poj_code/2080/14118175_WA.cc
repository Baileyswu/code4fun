#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char week[7][20] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int n;
	while(scanf("%d", &n))
	{
		if(n == -1)
			break;
		int m = n;
		n++;
		int sum = 0, yeap = 0, year;
		for(year = 2000;year < 2033;year++)
		{
			if((year%4==0)&&(year%100!=0)||(year%400==0))
				yeap = 1;
			sum += 365+yeap;
			if(n <= sum)
			{
				n -= sum-(365+yeap);
				break;
			}
			yeap = 0;
		}
		month[2] = yeap+28;
		sum = 0;
		int i;
		for(i = 1;i < 13;i++)
		{
			sum += month[i];
			if(n <= sum)
			{
				n -= sum-month[i];
				break;
			}
		}

		printf("%d-%02d-%02d %s\n", year, i, n, week[(m+6)%7]);
	}
	return 0;
}
