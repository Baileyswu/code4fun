#include <stdio.h>
#include <math.h>
#define N 59055
bool can[N];
int pr(int n)
{
	int i, s = pow(3, n);
	for(i = 1;i <= s;i++)
	{
		if(can[i])
			printf("-");
		else
			printf(" ");
	}
	return 0;
}
int zero(int n)
{
	int i, s = pow(3, n);
	for(i = 0;i < s;i++)
		printf(" ");
	return 0;
}
int main()
{
	int n, s = 1, i, v = 0;
	can[1] = 1;
	for(n = 1;n <= 10;i++)
	{
		for(i = s + 1;i <= 2*s;i++)
		{
			if(i >= N)
			{
				v = 1;
				break;
			}
			can[i] = 0;
		}
		for(;i <= 3*s;i++)
		{
			if(i >= N)
			{
				v = 1;
				break;
			}
			can[i] = can[i - 2*s];
		}
		if(v)
			break;
		s *= 3;
	}
	while(~scanf("%d", &n))
	{
		if(n <= 10)
		{
			pr(n);
			printf("\n");
		}
		if(n == 11)
		{
			pr(10);
			zero(10);
			pr(10);
			printf("\n");
		}
		if(n == 12)
		{
			pr(10);
			zero(10);
			pr(10);
			zero(11);
			pr(10);
			zero(10);
			pr(10);
			printf("\n");
		}
	}
	return 0;
}