#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define _max 20010
int p[_max], ans[105][_max], v;
int to(int x, int y)
{
	if(x == 0 || y == 0)
	{
		ans[x][y] = 0;
		return 0;
	}
	else if(!ans[x][y])
	{
		if(y > p[x])
			ans[x][y] = max(to(x-1, y), to(x-1, y-p[x])+p[x]);
		else
			ans[x][y] = to(x-1, y);
	}
	return ans[x][y];
}
int gao(int i, int re)
{
	if(i==0)
		return 0;
	if(ans[i][re] == ans[i-1][re])
	{
		gao(i-1, re);
		return 0;
	}
	gao(i-1, re-p[i]);
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
		memset(ans, 0, sizeof(ans));
		v = 0;
		double sum = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%lf", &num[i]);
			sum += num[i];
		}
		double k = 1.98039*(_max-1)/sum;
		for(int i = 1;i <= n;i++)
		{
			p[i] = k * num[i];
			//printf("%d%c", p[i], " \n"[i==n]);
		}

		int c = _max-1;
		ans[n][c] = to(n, c);
		//printf("%d %lf\n", ans[n][c], ans[n][c]/k);
		gao(n, c);
		printf("\n");
	}
	return 0;
}