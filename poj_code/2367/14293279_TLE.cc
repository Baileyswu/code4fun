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
vector<int> g[maxn];
int in[maxn], L[maxn], q, flag[maxn];
int input(int n)
{
	memset(g, 0, sizeof(g));
	memset(in, 0, sizeof(in));
	memset(flag, 0, sizeof(flag));

	int t;
	for(int i = 1;i <= n;i++)
	{
		while(scanf("%d", &t), t)
		{
			g[i].push_back(t);
			in[t]++;
		}
	}
}
int topo(int n)
{
	q = 0;
	//memcpy(in, rudu, sizeof(rudu));
	//pr(n);
	queue <int> Q;
	for(int i = 1;i <= n;i++)
		if(!in[i] && !flag[i])
		{
			flag[i] = 1;
			Q.push(i);
		}
	while(!Q.empty())
	{
		//if(Q.size() > 1)
		//	return 0;//看题意是否允许多个前向
		int y = Q.front();
		Q.pop();
		L[q++] = y;
		for(int j = 0;j < g[y].size();j++)
		{
			int t = g[y][j];
			in[t]--;
			if(!in[t] && !flag[t])
			{
				Q.push(t);
				flag[t] = 1;
			}
		}
	}
	//pr2();
	for(int i = 0;i < q;i++)
		printf("%d%c", L[i], " \n"[i==q-1]);
}
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		input(n);
		topo(n);
	}
}