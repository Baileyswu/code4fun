#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define maxn 1000005
#define rmax 1000000005
#define ll long long
using namespace std;
vector<pair<int, int> > g[maxn];
pair<int, int> temp;
int go[maxn];
int pr(int n)
{
	for(int i = 1;i <= n;i++)
		printf("%d%c", go[i], " \n"[i==n]);
}
int spfa(int n, int start)
{
	bool flag[maxn];
	queue <int> Q;
	memset(flag, false, sizeof(flag));
	for(int i = 1;i <= n;i++)
		go[i] = rmax;
	go[start] = 0;
	flag[start] = true;
	Q.push(start);
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for(int i = 0;i < g[u].size();i++)
		{
			int v = g[u][i].first, w = g[u][i].second;
			if(go[v] > go[u] + w)
			{
				go[v] = go[u] + w;
				if(!flag[v])
				{
					Q.push(v);
					flag[v] = true;
				}
			}
		}
	}
	//pr(n);
}
int init(int m)
{
	memset(g, 0, sizeof(g));
	int s, t, cost;
	for(int i = 0;i < m;i++)
	{
		scanf("%d%d%d", &s, &temp.first, &temp.second);
		g[s].push_back(temp);
	}
}
int solve(int n)
{
	long long sum = 0;
	spfa(n, 1);
	for(int i = 2;i <= n;i++)
		sum += (ll)go[i];
	for(int i = 2;i <= n;i++)
	{
		spfa(n, i);
		sum += (ll)go[1];
	}
	printf("%lld\n", sum);
}
int main()
{
	int f;
	scanf("%d", &f);
	while(f--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		init(m);
		solve(n);
	}
	return 0;
}