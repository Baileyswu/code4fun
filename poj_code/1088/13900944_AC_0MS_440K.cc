#include <stdio.h>
#include <string.h>
int R, C, set[105][105], mp[105][105], dp[8] = {1,0,0,1,-1,0,0,-1};
int dfs(int x, int y)
{
	if(mp[x][y])
		return mp[x][y];
	for(int i = 0;i < 4;i++)
	{
		int tx = x+dp[2*i], ty = y+dp[2*i+1];
		if(tx<0||tx>=R||ty<0||ty>=C)
			continue;
		if(set[tx][ty] > set[x][y])
		{
			int d = dfs(tx, ty);
			if(d+1 > mp[x][y])
				mp[x][y] = d+1;
		}
	}
	return mp[x][y];
}
int main()
{
	while(~scanf("%d%d", &R, &C))
	{
		memset(mp, 0, sizeof(mp));
		for(int i = 0;i < R;i++)
			for(int j = 0;j < C;j++)
				scanf("%d", &set[i][j]);
		int ans = 0;
		for(int i = 0;i < R;i++)
			for(int j = 0;j < C;j++)
			{
				int d = dfs(i, j);
				if(d > ans)
					ans = d;
			}
		printf("%d\n", ans+1);
	}
	return 0;
}