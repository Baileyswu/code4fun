#include <stdio.h>
#include <math.h>
int so(int a, int b)
{
	if(!a)
		return b;
	if(!b)
		return a;
	return so(b, a%b);
}
int main()
{
	int top[100000], but[100000];
	int n, m, i, j;
	while(scanf("%d%d", &n, &m), n)
	{
		int mm = m;
		if(m > n/2)
			m = n-m;
		for(i = 0;i < m;i++)
			but[i] = i+1, top[i] = n-m+i+1;
		for(i = 0;i < m;i++)
			for(j = 0;j < m;j++)
			{
				if(top[i]==1 || but[j]==1)
					continue;
				int d = so(top[i], but[j]);
				if(d != 1)
					top[i] /= d, but[j] /= d;
			}
		long long ans = 1;
		for(i = 0;i < m;i++)
			ans *= (long long)top[i];
		printf("%d things taken %d at a time is %lld exactly.\n", n, mm, ans);
	}
	return 0;
}
