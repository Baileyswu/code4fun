#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
bool flag[105][105];
int dp[8][2] = {1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
int n, m;
char a[105][105];
int solve(int x, int y)
{
	for(int i = 0;i < 8;i++)
	{
		int c = x+dp[i][0], d = y+dp[i][1];
		if(c < 0||c >= n||d < 0||d >=m)
			continue;
		if(a[c][d] == '.'||flag[c][d])
			continue;
		flag[c][d] = 1;
		solve(c,d);
	}
	return 0;
}
int main()
{
	int i, j, count = 0;
	scanf("%d%d", &n, &m);
	memset(flag, 0, sizeof(flag));
	for(i = 0;i < n;i++)
		scanf("%s", a[i]);
	for(int p = 0;p < n*m;p++)
	{
		if(a[p/m][p%m] == '.'||flag[p/m][p%m])
			continue;
		flag[p/m][p%m] = 1;
		solve(p/m, p%m);
		count++;
	}
	printf("%d\n", count);
	return 0;
}
