#include <stdio.h>
int top[1000], but[1000];
int gcd(int x, int y)
{
	if(!x)
		return y;
	if(!y)
		return x;
	return gcd(y, x%y);
}
int main()
{
	int n, k, d;
	while(scanf("%d%d", &n, &k), n)
	{
		if(k > n/2)
			k = n-k;
		for(int i = 0;i < k;i++)
		{
			but[i] = i+1;
			top[i] = n-i;
		}
		for(int t = 0;t < k;t++)
		{
			for(int i = 0;i < k;i++)
			{
				if(but[i] == 1)
					continue;
				d = gcd(but[i], top[t]);
				if(d!=1)
				{
					but[i] /= d;
					top[t] /= d;
				}
			}
		}
		long long ans = 1;
		for(int i = 0;i < k;i++)
			ans *= top[i];
		printf("%lld\n", ans);
	}
	return 0;
}