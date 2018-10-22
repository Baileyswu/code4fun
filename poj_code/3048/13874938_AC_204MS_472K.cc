#include <stdio.h>
#include <string.h>
#define N 20100
int prime[3000]={0,2}, num[N];
int set()
{
	int v = 1, p = 1;
	memset(num, 1, sizeof(num));
	num[0] = num[1] = 0;
	while(v)
	{
		for(int i = 2*prime[p];i < N;i+=prime[p])
			num[i] = 0;
		v = 0;
		for(int i = prime[p]+1;i < N;i++)
			if(num[i])
			{
				prime[++p] = i;
				v = 1;
				break;
			}
	}
	for(int i = 0;i < p;i++)
		num[prime[i]] = i;
	for(int i = 2;i < N;i++)
	{
		if(num[i])
			p = num[i];
		if(!num[i])
			num[i] = p;
	}
	return 0;
}
int main()
{
	set();
	int n;
	while(~scanf("%d", &n))
	{
		int m = 1, d = 0, q, com, ans = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &com);
			if(com == 1)
			{
				if(!d)
					ans = 1;
				continue;
			}
			q = num[com];
			for(int i = q;i > 0;i--)
				if(com % prime[i]==0)
				{
					d = prime[i];
					break;
				}
			if(d > m)
			{
				m = d;
				ans = com;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}