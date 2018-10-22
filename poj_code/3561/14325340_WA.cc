#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char str[15][15];
int n, m, dp[4][2] = {0, 1, 1, 0, 1, 1, -1, -1};
int solve(char type, int num, int i, int j)
{
	int ty;
	switch(type)
	{
		case '-': ty = 0;break;
		case '|': ty = 1;break;
		case '\\': ty = 2;break;
		case '/': ty = 3;break;
	}
	int px = i, py = j, r = 0;
	while(px>=0 && px<n && py>=0 && py<m)
	{
		if(str[px][py] != type)
			break;
		r++;
		px += dp[ty][0], py += dp[ty][1];
	}
	//printf("num:%d  r:%d\n", num, r);
	if(r == num)
		printf("CORRECT\n");
	else
		printf("INCORRECT\n");
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		int ans = 0, num = 1, x, y;
		char type = '.';
		for(int i = 0;i < n;i++)
		{
			scanf("%s", str[i]);
			for(int j = 0;j < m;j++)
			{
				if(str[i][j] == '.')
					continue;
				if(type == '.')
				{
					type = str[i][j];
					x = i, y = j;
				}
				else
				{
					if(type != str[i][j])
					{
						ans = 1;
						break;
					}
					else
						num++;
				}
			}
		}
		if(type == '.' || ans)
		{
			printf("INCORRECT\n");
			continue;
		}
		//printf("-------%c %d\n", type, num);
		solve(type, num, x, y);
	}
	return 0;
}