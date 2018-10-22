#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, mp[105][105], ans, dp[4][2] = {1,0,0,1,0,-1,-1,0}, f;
bool flag[105][105];
int solve(int x, int y)
{
	for(int i = 0;i < 4;i++)
	{
		int a = x+dp[i][0], b = y+dp[i][1];
		if(a<0||a>=n||b<0||b>=n)
			continue;
		if(mp[a][b]!=f || flag[a][b])
			continue;
		flag[a][b] = 1;
		ans++;
		solve(a, b);
	}
}
int main()
{
	int i, j, x, y;
	while(scanf("%d", &n), n)
	{
		if(n==1)
		{
			printf("good\n");
			continue;
		}
		memset(flag, 0, sizeof(flag));
		memset(mp, 0, sizeof(mp));
		for(i = 0;i < n-1;i++)
			for(j = 0;j < 2*n;j+=2)
			{
				scanf("%d%d", &x, &y);
				mp[x-1][y-1] = i+1;
			}
		for(i = 0;i < n;i++)
			for(j = 0;j < n;j++)
				if(!mp[i][j])
					mp[i][j] = n;
		int v = 0;
		for(f = 1;f <= 5;f++)
		{
			ans = 0;
			for(j = 0;j < n*n;j++)
			{
				if(flag[j/n][j%n]||mp[j/n][j%n]!=f)
					continue;
				flag[j/n][j%n] = 1;
				ans = 1;
				solve(j/n, j%n);
			}
			if(ans < n)
			{
				v = 1;
				break;
			}
		}
		if(v)
			printf("wrong\n");
		else
			printf("good\n");
	}
	return 0;
}