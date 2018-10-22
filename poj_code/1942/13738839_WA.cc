#include <stdio.h>
int top[100];
int bot[100];
int gcd(int a, int b)
{
	if(!a)
		return b;
	if(!b)
		return a;
	else
		return gcd(b, a%b);
}
int main()
{
	int n, m, i;
	while(scanf("%d%d", &n, &m), n)
	{
		if(n > m)
		{
			n = n^m;
			m = n^m;
			n = n^m;
		}
		for(i = 0;i < n;i++)
		{
			bot[i] = i+1;
			top[i] = m+i+1;
		}
		for(int k = 0;k < n;k++)
		{
			for(i = 0;i < n;i++)
			{
				if(bot[i] == 1)
					continue;
				int d = gcd(bot[i], top[k]);
				if(d == 1)
					continue;
				bot[i] /= d;
				top[k] /= d;
			}
		}
		unsigned int ans = 1;
		for(i = 0;i < n;i++)
			ans *= top[i];
		printf("%d\n", ans);
	}
	return 0;
}