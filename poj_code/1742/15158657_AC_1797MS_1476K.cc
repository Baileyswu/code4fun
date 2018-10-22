#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int a[110], c[110], ans[100100], cnt[100100];
int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m))
	{
		if(!n && !m) break;
		for(int i = 0;i < n;i++)
			scanf("%d", &a[i]);
		for(int i = 0;i < n;i++)
			scanf("%d", &c[i]);
		memset(ans, 0, sizeof(ans));
		ans[0] = 1;
		int t = 0;
		for(int j = 0;j < n;j++)
		{
			for(int i = 0;i <= m;i++) cnt[i] = 0;
			for(int i = a[j];i <= m;i++) if(!ans[i])
				if(i-a[j] >= 0 && cnt[i-a[j]]+1 <= c[j] && ans[i-a[j]])
				{
					ans[i] = 1;
					cnt[i] = cnt[i-a[j]]+1;
				}
			// for(int i = 1;i <= m;i++)
			// 	printf("%d%c", ans[i], " \n"[i == m]);
		}
		int pp = 0;
		for(int i = 1;i <= m;i++)
			pp += ans[i];
		printf("%d\n", pp);
	}
	return 0;
}