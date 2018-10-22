#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
#define N 300010
bool flag[N];
int dp[3] = {1, -1};
typedef struct node
{
	int x, s;
}NO;
queue <NO> line;
int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		if(n >= m)
		{
			printf("%d\n", n-m);
			continue;
		}
		memset(flag, 0, sizeof(flag));
		NO sta;
		sta.x = n, sta.s = 0;
		flag[n] = 1;
		int v = 0;
		while(sta.x != m)
		{
			//printf("%d %d\n", sta.x, sta.s);
			dp[2] = sta.x;
			for(int i = 0;i < 3;i++)
			{
				int temp = sta.x + dp[i];
				if(temp < 1 || temp >= N || flag[temp])
					continue;
				flag[temp] = 1;
				NO t;
				t.x = temp, t.s = sta.s+1;
				line.push(t);
				if(temp == m)
				{
					v = 1;
					printf("%d\n", t.s);
					break;
				}
			}
			if(v)break;
			sta = line.front();
			line.pop();
		}
		while(!line.empty())
			line.pop();
	}
	return 0;
}