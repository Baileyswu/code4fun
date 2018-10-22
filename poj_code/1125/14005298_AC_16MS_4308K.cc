#include <stdio.h>
#include <string.h>
#define Max 1000000000
int mp[1005][1005], n;
int floyd()
{
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(mp[i][k] + mp[k][j] < mp[i][j])
					mp[i][j] = mp[i][k]+mp[k][j];
	return 0;
}
int main()
{
	int t, vert, edge;
	while(scanf("%d", &n), n)
	{
		memset(mp, 0, sizeof(mp));
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d%d", &vert, &edge);
				if(!mp[i][vert] || mp[i][vert] > edge)
					mp[i][vert] = edge;
			}
		}
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(i != j && !mp[i][j])
					mp[i][j] = Max;
		floyd();
		int ans = Max, p = 0;
		for(int i = 1;i <= n;i++)
		{
			int temp = 0;
			for(int j = i+1;j <= i+n;j++)
				if(mp[i][(j-1)%n+1] > temp)
					temp = mp[i][(j-1)%n+1];
			if(temp < ans)
			{
				ans = temp;
				p = i;
			}
		}
		if(ans == Max)
			printf("disjoint\n");
		else
			printf("%d %d\n", p, ans);
	}
	return 0;
}