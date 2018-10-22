#include <cstdio>
#include <cstring>
int peak, v;
int solve(int i, int h)
{
	if(peak < h)
	{
		v = 0;
		peak = h;
	}
	else if(peak > h)
	{
		if(!v)
			printf("%d\n", i);
		v = 1;
		peak = h;
	}
	else if(peak == h)
		return 1;
	return 0;
}
int main()
{
	int n, h;
	while(~scanf("%d", &n))
	{
		peak = 0, v = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &h);
			if(solve(i, h))
			{
				solve(i, 0);
				peak = v = 0;
				solve(i, h);
			}
		}
		solve(n, 0);
	}
	return 0;
}