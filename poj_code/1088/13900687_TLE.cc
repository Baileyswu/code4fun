#include <stdio.h>
#include <string.h>
int dp[8] = {1,0,0,1,0,-1,-1,0};
int R, C, set[105][105], mp[105][105], p;
int ok(int x, int y)
{
	if(mp[x][y] > p)
		p = mp[x][y];
	for(int i = 0;i < 4;i++)
	{
		int a = x+dp[2*i], b = y+dp[2*i+1];
		if(a<0 || a>=R || b<0 || b >= C)
			continue;
		if(mp[a][b] <= mp[x][y] && set[a][b] < set[x][y])
		{
			mp[a][b] = mp[x][y] + 1;
			ok(a, b);
		}
	}
}
int main()
{
	int i, j, ans = 0;
	scanf("%d%d", &R, &C);
	for(i = 0;i < R;i++)
		for(j = 0;j < C;j++)
			scanf("%d", &set[i][j]);
	for(i = 0;i < R;i++)
		for(j = 0;j < C;j++)
		{
			memset(mp, 0, sizeof(mp));
			mp[i][j] = 1, p = 0;
			ok(i, j);
			if(p > ans)
				ans = p;
		}
	printf("%d\n", ans);
	return 0;
}