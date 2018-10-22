#include <stdio.h>
#include <algorithm>
#include <mem.h>
using namespace std;
int n, k;
bool row[9];
char map[9][9];
int dfs(int k, int line)
{
	if(n - line < k)
		return 0;
	if(k == 0 && line == n)
		return 1;
	int count = 0;
	for(int i = 0;i < n;i++)
	{
		if(row[i] && map[line][i] == '#')
		{
			row[i] = false;
			count += dfs(k - 1, line + 1);
			row[i] = true;
		}
	}
	count += dfs(k, line + 1);
	return count;
}
int main()
{
	int i, j;
	while(scanf("%d%d", &n, &k) && n != -1)
	{
		for(i = 0;i < n;i++)
			scanf("%s", map[i]);
		memset(row, true, n);
		int ans =  dfs(k, 0);
		printf("%d\n", ans);
	}
	return 0;
}