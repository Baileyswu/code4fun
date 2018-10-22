#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
bool flag[25][25];
int n, m, ans;
int dp[4][2] = {1,0,-1,0,0,1,0,-1};
char mp[25][25];
int solve(int a, int b)
{
	for(int i = 0;i < 4;i++)
	{
		int x = a + dp[i][0], y = b + dp[i][1];
		if(x<0||x>=n||y<0||y>=m)
			continue;
		if(mp[x][y]=='#'||flag[x][y])
			continue;
		flag[x][y] = 1;
		ans++;
		solve(x,y);
	}
	return 0;
}
int main()
{
	while(scanf("%d%d", &m, &n), m)
	{
		int i, j, v = 0;
		ans = 1;
		memset(flag, 0, sizeof(flag));
		for(i = 0;i < n;i++)
			scanf("%s", mp[i]);
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < m;j++)
				if(mp[i][j] == '@')
				{
					v = 1;
					break;
				}
			if(v)
				break;
		}
		flag[i][j] = 1;
		solve(i, j);
		printf("%d\n", ans);
	}
	return 0;
}
