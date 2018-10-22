#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define _max 20010
int p[_max], ans[105][_max], flag[105][_max], v;
int solve(int n, int c)
{
	memset(flag, 0, sizeof(flag));
	for(int j = 0;j < c;j++)
		ans[0][j] = 0;
	for(int i = 1;i <= n;i++)
	{
		ans[i][0] = 0;
		for(int j = 1;j <= c;j++)
			if(j > p[i])
				ans[i][j] = max(ans[i-1][j], ans[i-1][j-p[i]]+p[i]);
	}
	//printf("%d %d\n", c, ans[n][c]);
return 0;
}
int gao(int i, int re)
{
	if(i==0)
	{
		//printf("no\n");
		return 0;
	}
	if(ans[i][re] == ans[i-1][re])
	{
		gao(i-1, re);
		return 0;
	}
	gao(i-1, re - p[i]);
	if(v)
		printf(" ");
	printf("%d", i);
	v = 1;
	return 0;
}
int main()
{
	int n;
	double num[105];
	while(scanf("%d", &n), n)
	{
		v = 0;
		double sum = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%lf", &num[i]);
			sum += num[i];
		}
		double k = 2*_max/sum;
		for(int i = 1;i <= n;i++)
			p[i] = k * num[i];
		int c = k*sum/2;
		solve(n, c);
		//printf("%lf\n", ans[n][c]/k);
		gao(n, c);
		printf("\n");
	}
	return 0;
}