#include <stdio.h>
#include <string.h>
#include <math.h>
int a[15][2], p;
int ok(int x)
{
	if(a[p][0])
	{
		if(a[p][0] == x)
			a[p][1]++;
		else
		{
			a[++p][0] = x;
			a[p][1]++;
		}
	}
	else
		a[p][0] = x, a[p][1] = 1;
	return 0;
}
int gcd(int x, int y)
{
	if(x==0)return y;
	if(y==0)return x;
	return gcd(y, x%y);
}
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		p = 0;
		memset(a, 0, sizeof(a));
		int i;
		while(n > 1)
		{
			int v = 0;
			for(i = 2;i <= sqrt(n)+1;i++)
				if(n%i == 0)
				{
					ok(i);
					n /= i;
					v = 1;
					break;
				}
			if(!v)
				break;
		}
		if(n > 1)
			ok(n);
		int ans = 0;
		for(i = 0;i < p+3&&i<15;i++)
		{
			//printf("%d %d\n", a[i][0], a[i][1]);
			ans = gcd(ans, a[i][1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}