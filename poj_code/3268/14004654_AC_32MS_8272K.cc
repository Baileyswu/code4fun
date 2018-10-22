#include <stdio.h>
#include <string.h>
#include <math.h>
#define Max 1000000000
int n, mp[2][1005][1005], flag[1005], ans[1005];
int min(int x, int y)
{
	return x < y?x : y;
}
int max(int x, int y)
{
	return x > y?x : y;
}
int dijkstra(int x, int mode)
{
	memset(flag, 0, sizeof(flag));
	memset(ans, 0, sizeof(ans));
	for(int i = 1;i <= n;i++)
		ans[i] = Max;
	ans[x] = 0, flag[x] = 1;
	int p = 0, q = x, next;
	while(p != q)
	{
		p = q;
		next = Max;
		for(int i = 1;i <= n;i++)
		{
			if(!flag[i] && mp[mode][p][i])
				ans[i] = min(ans[i], mp[mode][p][i]+ans[p]);
			if(!flag[i] && ans[i] < next)
			{
				next = ans[i];
				q = i;
			}
		}
		flag[q] = 1;
	}
	return 0;
}
int main()
{
	int m, host;
	while(~scanf("%d%d%d", &n, &m, &host))
	{
		memset(mp, 0, sizeof(mp));
		while(m--)
		{
			int start, end, dis;
			scanf("%d%d%d", &start, &end, &dis);
			if(!mp[0][start][end] || mp[0][start][end] < dis)
			{
				mp[0][start][end] = mp[1][end][start] = dis;
			}
		}
		dijkstra(host, 0);
		int back[1005];
		for(int i = 1;i <= n;i++)
			back[i] = ans[i];
		dijkstra(host, 1);
		int ask = 0;
		for(int i = 1;i <= n;i++)
		{
			int dis = back[i] + ans[i];
			if(dis > ask)
				ask = dis;
		}
		printf("%d\n", ask);
	}
	return 0;
}