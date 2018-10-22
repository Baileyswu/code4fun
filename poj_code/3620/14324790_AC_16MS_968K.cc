#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define maxn 1005
int mp[105][105], flag[105][105], n, m, dp[4][2] = {0,1,0,-1,1,0,-1,0};

int clear()
{
	memset(mp, 0, sizeof(mp));
	memset(flag, 0, sizeof(flag));
}
int input(int k)
{
	int x, y;
	while(k--)
	{
		scanf("%d%d", &x, &y);
		mp[x][y] = 1;
	}
}
int dfs(int x, int y)
{
	int r = 1;
	for(int k = 0;k < 4;k++)
	{
		int tx = x+dp[k][0], ty = y+dp[k][1];
		if(tx < 1 || tx > n || ty < 1 || ty > m || flag[tx][ty])
			continue;
		flag[tx][ty] = 1;
		if(mp[tx][ty])
			r += dfs(tx, ty);
	}
	return r;
}
int solve(int k)
{
	int ans = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <=m;j++)
		{
			if(flag[i][j])
				continue;
			flag[i][j] = 1;
			if(mp[i][j])
			{
				int t = dfs(i, j);
				if(t > ans)
					ans = t;
			}
		}
	printf("%d\n", ans);
}
int main()
{
	int k;
	while(~scanf("%d%d%d", &n, &m, &k))
	{
		clear();
		input(k);
		solve(k);
	}
	return 0;
}