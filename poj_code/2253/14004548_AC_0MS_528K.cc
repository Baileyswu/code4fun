#include <stdio.h>
#include <string.h>
#include <math.h>
#define Max 1000000000
int n, mp[205][205], flag[205], ans[205];
struct node
{
	int x, y;
}np[205];
int min(int x, int y)
{
	return x < y?x : y;
}
int max(int x, int y)
{
	return x > y?x : y;
}
int dijkstra()
{
	ans[1] = 0, flag[1] = 1;
	int p = 1, q, next;
	while(p != 2)
	{
		next = Max;
		for(int i = 2;i <= n;i++)
		{
			if(!flag[i])
				ans[i] = min(ans[i], max(mp[i][p], ans[p]));
			if(!flag[i] && ans[i] < next)
			{
				next = ans[i];
				q = i;
			}
		}
		p = q;
		flag[q] = 1;
	}
	printf("Frog Distance = %.3f\n\n", sqrt(ans[2]));
	return 0;
}
int main()
{
	int t = 0;
	while(scanf("%d", &n), n)
	{
		memset(mp, 0, sizeof(mp));
		memset(flag, 0, sizeof(flag));
		memset(ans, 0, sizeof(ans));
		for(int i = 1;i <= n;i++)
			scanf("%d%d", &np[i].x, &np[i].y);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				mp[i][j] = mp[j][i] = (np[i].x-np[j].x)*(np[i].x-np[j].x)+(np[i].y-np[j].y)*(np[i].y-np[j].y);
		for(int i = 1;i <= n;i++)
			ans[i] = Max;
		printf("Scenario #%d\n", ++t);
		dijkstra();
	}
	return 0;
}