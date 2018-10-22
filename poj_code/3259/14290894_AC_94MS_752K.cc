#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define maxn 100005
using namespace std;
int nume, dist[maxn];
struct node
{
	int u, v, w;
	node(){}
	node(int a, int b, int c){
		u = a, v = b, w = c;
	}
}edge[maxn];
int add(int s, int t, int cost)
{
	edge[nume++] = node(s, t, cost);
}
int init(int m, int w)
{
	nume = 0;
	int s, t, cost;
	for(int i = 0;i < m;i++)
	{
		scanf("%d%d%d", &s, &t, &cost);
		add(s, t, cost);
		add(t, s, cost);
	}
	for(int i = 0;i < w;i++)
	{
		scanf("%d%d%d", &s, &t, &cost);
		add(s, t, -cost);
	}
}
int pr(int n)
{
	for(int i = 1;i <= n;i++)
		printf("%d%c", dist[i], " \n"[i==n]);
}
int debellman(int n)
{
	dist[1] = 0;
	for(int i = 2;i <= n;i++)
		dist[i] = maxn;
	for(int k = 0;k < n-1;k++)
	{
		for(int i = 0;i < nume;i++)
		{
			if(dist[edge[i].v] > dist[edge[i].u] + edge[i].w)
			{
				dist[edge[i].v] = dist[edge[i].u] + edge[i].w;
			}
		}
	}
	//pr(n);
	for(int i = 0;i < nume;i++)
	{
		if(dist[edge[i].v] > dist[edge[i].u] + edge[i].w)
			return 1;
	}
	return 0;
}
int main()
{
	int f;
	scanf("%d", &f);
	while(f--)
	{
		int n, m, w;
		scanf("%d%d%d", &n, &m, &w);
		init(m, w);
		int ans = debellman(n);
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}