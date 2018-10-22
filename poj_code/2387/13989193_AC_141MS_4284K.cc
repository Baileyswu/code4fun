#include <stdio.h>
#include <string.h>
#define ma 100000000
int main()
{
	int T, N, mp[1005][1005], ans[1005], flag[1005], f, t, p;
	while(~scanf("%d%d", &T, &N))
	{
		memset(mp, 0, sizeof(mp));
		memset(ans, 0, sizeof(ans));
		memset(flag, 0, sizeof(flag));
		while(T--)
		{
			scanf("%d%d%d", &f, &t, &p);
			if(!mp[f][t] || p < mp[f][t])
				mp[f][t] = mp[t][f] = p;
		}
		int mi = ma, point = 1, q;
		for(int i = 1;i <= N;i++)
			ans[i] = ma;
		ans[1] = 0, flag[1] = 1;
		while(point != N)
		{
			mi = ma;
			for(int i = 2;i <= N;i++)
			{
				if(mp[i][point] && !flag[i])
				{
					int d = mp[i][point]+ans[point];
					if(d < ans[i])
						ans[i] = d;
				}
				if(!flag[i] && ans[i] < mi)
					mi = ans[i], q = i;
			}
			point = q;
			flag[point] = 1;
		}
		printf("%d\n", ans[N]);
	}
	return 0;
}
