#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int x, ans = 0, t;
		scanf("%d", &x);
		if(x & 1LL)
		{
			while(n--)
			{
				scanf("%d", &t);
				if(t > 0)
					ans += pow(t, x);
			}
		}
		else
		{
			while(n--)
			{
				scanf("%d", &t);
				ans += pow(t, x);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}