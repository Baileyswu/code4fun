#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
bool flag[105][105];
int n, m, dp[8][2] = {1,0,1,-1,0,-1,-1,-1,-1,0,-1,1,0,1,1,1};
char mp[105][105];
int solve(int x, int y)
{
	for(int i = 0;i < 8;i++)
	{
		int a = x+dp[i][0], b = y+dp[i][1];
		if(a<0||a>=n||b<0||b>=m)
			continue;
		if(mp[a][b]=='*'||flag[a][b])
			continue;
		flag[a][b] = 1;
		solve(a, b);
	}
	return 0;
}
int main()
{
	int i, j;
	while(scanf("%d%d", &n, &m), n)
	{
		memset(flag, 0, sizeof(flag));
		int count = 0;
		for(i = 0;i < n;i++)
			scanf("%s", mp[i]);
		for(int p = 0;p < m*n;p++)
		{
			if(mp[p/m][p%m]=='*'||flag[p/m][p%m])
				continue;
			flag[p/m][p%m] = 1;
			solve(p/m, p%m);
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
