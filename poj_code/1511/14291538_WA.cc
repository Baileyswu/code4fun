#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define maxn 1000005
#define rmax 1000000000005
#define ll long long
using namespace std;
vector<pair<int, ll> > g[2][maxn];
pair<int, ll> temp;
ll dist[maxn];
int pr(int n)
{
	for(int i = 1;i <= n;i++)
		printf("%lld%c", dist[i], " \n"[i==n]);
}
int spfa(int n, int r)
{
	bool flag[maxn];
	queue <int> Q;
	memset(flag, 0, sizeof(flag));
	for(int i = 1;i <= n;i++)
		dist[i] = rmax;
	dist[1] = 0;
	flag[1] = true;
	Q.push(1);
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for(int i = 0;i < g[r][u].size();i++)
		{
			int v = g[r][u][i].first;
			ll w = g[r][u][i].second;
			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
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
	int s, t;
	for(int i = 0;i < m;i++)
	{
		scanf("%d%d%lld", &s, &t, &temp.second);
		temp.first = t;
		g[0][s].push_back(temp);
		temp.first = s;
		g[1][t].push_back(temp);
	}
}
int solve(int n)
{
	spfa(n, 0);
	ll sum = 0;
	for(int i = 2;i <= n;i++)
		sum += dist[i];
	spfa(n, 1);
	for(int i = 2;i <= n;i++)
		sum += dist[i];
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