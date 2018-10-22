#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef struct node
{
	int x,y,co;
}No;
No sta,end;
queue<No> line;
int n, a, b, c, d, f, g;
int dp[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
bool mp[305][305];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(mp, false, sizeof(mp));
		scanf("%d%d%d%d%d", &n,&a,&b,&c,&d);
		sta.x = a, sta.y = b, sta.co = 0;
		line.push(sta);
		mp[a][b] = 1;
		while(1)
		{
			end = line.front();
			line.pop();
			a = end.x, b = end.y;
			if(a == c && b == d)
			{
				printf("%d\n", end.co);
				break;
			}
			for(int i = 0;i < 8;i++)
			{
				f = a+dp[i][0];
				g = b+dp[i][1];
				if(f < 0 || f >= n || g < 0 || g >= n)
					continue;
				if(!mp[f][g])
				{
					mp[f][g] = 1;
					sta.x = f, sta.y = g, sta.co = end.co+1;
					line.push(sta);
				}
			}
		}
	}
	return 0;
}