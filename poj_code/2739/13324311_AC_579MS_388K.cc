#include <stdio.h>
#define range 10000
bool IsPrime[range+1];
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
int cal(int x, int max)
{
	int s = x - max;
	for(int i = max - 1;i > 1;i--)
		if(IsPrime[i] && s > 0)
			s -= i;
	if(!s)
		return 0;
	else
		return 1;
}
int main()
{
	int x, count, t;
	set();
	while(scanf("%d", &x) && x)
	{
		count = 0;
		for(int i = x;i > 1;i--)
			if(IsPrime[i])
			{
				t = cal(x, i);
				if(!t)
					count++;
			}
		printf("%d\n", count);
	}
	return 0;
}