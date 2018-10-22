#include <stdio.h>
#include <string.h>
#define maxn 1005
int num[maxn];
int pr(int n)
{
	for(int i = 0;i < n;i++)
		printf("%d%c", num[i], " \n"[i == n-1]);
}
int main()
{
	int n, T;
	while(~scanf("%d%d", &n, &T))
	{
		int ma = 0, ans = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &num[i]);
			if(num[i] > ma)
			{
				ma = num[i];
				ans = i;
			}
		}
		while(T--)
		{
			//pr(n);
			printf("%d\n", ans+1);
			int p = num[ans] / (n-1), q = num[ans] % (n-1);
			num[ans] = ma = 0;
			int t = ans;
			for(int i = 0;i < q;i++)
			{
				if(i == t)
					q++;
				else
					num[i] += p+1;
				if(num[i] > ma)
				{
					ma = num[i];
					ans = i;
				}
			}
			for(int i = q;i < n;i++)
			{
				if(i == t)
					continue;
				num[i] += p;
				if(num[i] > ma)
				{
					ma = num[i];
					ans = i;
				}
			}
		}
	}
	return 0;
}