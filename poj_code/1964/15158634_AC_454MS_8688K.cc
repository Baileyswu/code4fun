#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1010
int n, m, mp[N][N], ans[N][N], l[N], r[N];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		char str[10000];
		memset(mp, 0, sizeof(mp));
		memset(ans, 0, sizeof(ans));
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
			{
				scanf("%s", str);
				if(str[0] == 'F')
					mp[i][j] = 0;
				else if(str[0] == 'R')
					mp[i][j] = 1;
			}
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
			{
				if(!mp[i][j])
					ans[i][j] = ans[i-1][j] + 1;
				// printf("%d%c", ans[i][j], " \n"[j==m]);
			}
		int _max = 0;
		for(int i = 1;i <= n;i++)
		{
			l[1] = 1; r[m] = m;
			for(int j = 2;j <= m;j++)
			{
				//l[j] = ans[i][j] <= ans[i][j-1] ? l[j-1] : j;
				l[j] = j;
				while(l[j]-1 >= 1 && ans[i][j] <= ans[i][l[j]-1])
					l[j] = l[l[j]-1];
			}
			for(int j = m-1;j >= 1;j--)
			{
				// r[j] = ans[i][j] <= ans[i][j+1] ? r[j+1] : j;
				r[j] = j;
				while(r[j]+1 <= m && ans[i][j] <= ans[i][r[j]+1])
					r[j] = r[r[j]+1];
			}
			for(int j = 1;j <= m;j++)
			{
				// printf("%d %d %d\n", ans[i][j], l[j], r[j]);
				_max = max(_max, ans[i][j]*(r[j]-l[j]+1));
			}
		}
		printf("%d\n", _max*3);
	}
	return 0;
}