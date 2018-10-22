#include <stdio.h>
long long top[1000];
long long bot[1000];
int gcd(long long a, long long b)
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
	long long n, m, i;
	while(scanf("%lld%lld", &n, &m), n)
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
		for(long long k = 0;k < n;k++)
		{
			for(i = 0;i < n;i++)
			{
				if(bot[i] == 1)
					continue;
				long long d = gcd(bot[i], top[k]);
				if(d == 1)
					continue;
				bot[i] /= d;
				top[k] /= d;
			}
		}
		long long ans = 1;
		for(i = 0;i < n;i++)
			ans *= (long long) top[i];
		printf("%lld\n", ans);
	}
	return 0;
}