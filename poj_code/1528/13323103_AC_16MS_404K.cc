#include <stdio.h>
#include <math.h>
int factor[100][2], f=0;
int div(int x)
{
	for(int i = 2;i <= x;i++)
	{
		if(x % i == 0)
		{
			if(factor[f][0] == i)
				factor[f][1]++;
			else
			{
				f++;
				factor[f][0] = i;
				factor[f][1] = 1;
			}
			div(x/i);
			return 0;
		}
	}
	return 0;
}
int cal(int x)
{
	f = 0;
	factor[0][0] = 1;
	div(x);
	int sum = 1;
	for(int i = 1;i <= f;i++)
		sum *= (pow(factor[i][0], factor[i][1] + 1) - 1)/(factor[i][0] - 1);
	return sum - 2 * x;
}
int main()
{
	printf("PERFECTION OUTPUT\n");
	int x, t;
	while(scanf("%d", &x) && x)
	{
		t = cal(x);
		if(!t)
			printf("%5d  PERFECT\n", x);
		else if(t > 0)
			printf("%5d  ABUNDANT\n", x);
		else
			printf("%5d  DEFICIENT\n", x);
	}
	printf("END OF OUTPUT\n");
	return 0;
}