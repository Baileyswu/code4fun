#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 110000
typedef vector<int> VCI;
vector<VCI> T(N);
int lef[N], rig[N], n, cnt, a[2*N], C[2*N], L[2*N];
void init()
{
	for(int i = 0;i <= n;i++)
		T[i].clear();
	for(int i = 1;i < n;i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		T[u].push_back(v);
	}
	cnt = 0;
}
void dfs(int x)
{
	lef[x] = ++cnt;
	for(int i = 0;i < T[x].size();i++)
		dfs(T[x][i]);
	rig[x] = ++cnt;
	a[lef[x]] = a[rig[x]] = 1;
}
void set()
{
	for(int x = 1;x <= 2*N;x++)
		L[x] = x&(x^(x-1));
}
void give()
{
	for(int i = 1;i <= 2*n;i++)
		C[i] = L[i];
}
int sum(int x)
{
	int r = 0;
	while(x > 0)
	{
		r += C[x];
		x -= L[x];
	}
	return r;
}
void modify(int x, int y)
{
	int i = x;
	while(i <= 2*n)
	{
		C[i] += - a[x] + y;
		i += L[i];
	}
	a[x] = y;
}
int main()
{
	set();
	while(~scanf("%d", &n))
	{
		init();
		dfs(1);
		give();
		int m;
		scanf("%d", &m);
		while(m--)
		{
			char str[2];
			int x;
			scanf("%s%d", str, &x);
			if(str[0] == 'Q')
				printf("%d\n", (sum(rig[x])-sum(lef[x]-1))/2);
			else{
				modify(rig[x], 1-a[rig[x]]);
				modify(lef[x], 1-a[lef[x]]);
			}
		}
	}
	return 0;
}