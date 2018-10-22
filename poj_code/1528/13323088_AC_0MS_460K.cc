#include <stdio.h>
#include <math.h>
#define range 60000
bool IsPrime[range+1];
int factor[100][2], f=0;
int set()
{
    int i,j;
    for(i=2;i<=range;i++)
        IsPrime[i]=true;
    IsPrime[0]=false;
    IsPrime[1]=false;
    for(i=2;i<=range;i++)
    {
        if(IsPrime[i])
        {
            for(j=2*i;j<=range;j+=i)
                IsPrime[j]=false;
        }
    }
    return 0;
}
int div(int x)
{
	for(int i = 1;i <= x;i++)
	{
		if(IsPrime[i] && (x % i == 0))
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
	set();
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