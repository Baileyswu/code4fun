#include <stdio.h>
#include <string.h>
int mp[105][105], n, flag[105], ans[105];
#define Max 1000000000
int min(int x, int y)
{
	return x < y? x:y;
}
int dijkstra(int a, int b)
{
	flag[a] = 1, ans[a] = 0;
	int p = a, q;
	while(p != b)
	{
		int next = Max;
		for(int i = 1;i <= n;i++)
		{
			if(!flag[i] && mp[p][i])
				ans[i] = min(ans[i], ans[p] + mp[p][i] - 1);
			if(!flag[i] && ans[i] < next)
			{
				next = ans[i];
				q = i;
			}
		}
		p = q;
		flag[p] = 1;
	}
	printf("%d\n", ans[b]);
	return 0;
}
int main()
{
	int a, b, k, end, pass;
	while(~scanf("%d%d%d", &n, &a, &b))
	{
		memset(mp, 0, sizeof(mp));
		memset(flag, 0, sizeof(flag));
		memset(ans, 0, sizeof(ans));
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", &k);
			for(int j = 0;j < k;j++)
			{
				scanf("%d", &end);
				if(j)
					pass = 2;
				else
					pass = 1;
				if(!mp[i][end] || mp[i][end] > pass)
					mp[i][end] = pass;
			}
		}
		for(int i = 1;i <= n;i++)
			ans[i] = Max;
		dijkstra(a, b);
	}
	return 0;
}