#include <stdio.h>
#include <string.h>
#define Max 1000000000
int n, m, mp[1005][1005], flag[1005], ans[1005];
int min(int x, int y)
{
	return x < y?x:y;
}
int dijkstra()
{
	int p = 1, q, next, co = 0;
	flag[1] = 1, ans[1] = Max;
	while(p != n && co++ < n+5)
	{
		next = 0;
		for(int i = 2;i <= n;i++)
		{
			if(!flag[i] && mp[p][i])
				ans[i] = min(ans[p], mp[i][p]);
			if(!flag[i] && next < ans[i])
			{
				next = ans[i];
				q = i;
			}
		}
		flag[q] = 1;
		p = q;
	}
	printf("%d\n\n", ans[n]);
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int ss = 1;ss <= t;ss++)
	{
		int start, end, edge;
		scanf("%d%d", &n, &m);
		memset(flag, 0, sizeof(flag));
		memset(mp, 0, sizeof(mp));
		memset(ans, 0, sizeof(ans));
		while(m--)
		{
			scanf("%d%d%d", &start, &end, &edge);
			if(!mp[start][end] || mp[start][end] < edge)
				mp[start][end] = mp[end][start] = edge;
		}
		for(int i = 1;i <= n;i++)
			ans[i] = 0;
		printf("Scenario #%d:\n", ss);
		dijkstra();
	}
	return 0;
}
