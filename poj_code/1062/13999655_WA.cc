#include <stdio.h>
#include <string.h>
#define Max 1000000000
int mp[105][105], flag[105], ans[105], N, M;
struct node
{
	int vert, stage, top, but;
}p[105];
int min(int x, int y)
{
	return x < y?x:y;
}
int max(int x, int y)
{
	return x > y?x:y;
}
int dijkstra()
{
	int q = 0, qt = 1, Min;
	flag[1] = 1, ans[1] = 0;
	p[1].top = p[1].but = p[1].stage;
	while(q != qt)
	{
		q = qt;
		Min = Max;
		for(int i = 2;i <= N;i++)
		{
			if(mp[i][q] && !flag[i])
			{
				if(p[i].stage < p[q].but - M || p[i].stage > p[q].top + M)
					flag[i] = -1;
				else
				{
					p[i].top = max(p[q].top, p[i].stage);
					p[i].but = min(p[q].but, p[i].stage);
					int d = mp[i][q] + ans[q];
					if(d < ans[i])
						ans[i] = d;
				}
			}
			if(!flag[i] && ans[i] < Min)
			{
				Min = ans[i];
				qt = i;
			}
		}
	}
	Min = Max;
	for(int i = 1;i <= N;i++)
	{
		if(ans[i] < Min)
			Min = min(Min, ans[i]+=p[i].vert);
	}
	printf("%d\n", Min);
}
int main()
{
	while(~scanf("%d%d", &M, &N))
	{
		memset(mp, 0, sizeof(mp));
		memset(flag, 0, sizeof(flag));
		memset(ans, 0, sizeof(ans));
		int k, edge, num, temp;
		for(int i = 1;i <= N;i++)
		{
			scanf("%d%d%d", &p[i].vert, &p[i].stage, &k);
			while(k--)
			{
				scanf("%d%d", &num, &temp);
				if(!mp[i][num] || mp[i][num] > temp)
					mp[i][num] = mp[num][i] = temp;
			}
		}
		for(int i = 1;i <= N;i++)
			ans[i] = Max;
		dijkstra();
	}
	return 0;
}