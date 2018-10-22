#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define maxn 100005
using namespace std;
int rudu[maxn], L[maxn], q, in[maxn];
vector <int> g[maxn];
int flag[28][28];
int clear()
{
	memset(L, 0, sizeof(L));
	memset(g, 0, sizeof(g));
	memset(flag, 0, sizeof(flag));
	memset(rudu, 0, sizeof(rudu));
	q = 0;
}
int signal(int u, int v)
{
	for(int i = 0;i < g[v].size();i++)
	{
		flag[u][g[v][i]] = 1;
		if(flag[g[v][i]][u])
			return 1;
	}
	return 0;
}
int pr(int n)
{
	for(int i = 1;i <= n;i++)
	{
		printf("%d:", i);
		for(int j = 0;j < g[i].size();j++)
		{
			int s = g[i][j];
			printf("%d ", s);
		}
		printf("\n");
	}
}
int iiii(int n)
{
	printf("**in\n");
	for(int i = 1;i <= n;i++)
		printf("%d%c", rudu[i], " \n"[i==n]);
}
int pr2()
{
	printf("-----------\n");
	for(int i = 0;i < q;i++)
		printf("%d%c", L[i], " \n"[i==q-1]);
	printf("===========\n");
}
int topo(int n)
{
	q = 0;
	memcpy(in, rudu, sizeof(rudu));
	//pr(n);
	queue <int> Q;
	for(int i = 1;i <= n;i++)
		if(!in[i] && flag[i][0])
			Q.push(i);
	while(!Q.empty())
	{
		//iiii(n);
		int y = Q.front();
		Q.pop();
		L[q++] = y;
		for(int j = 0;j < g[y].size();j++)
		{
			int t = g[y][j];
			in[t]--;
			if(!in[t])
				Q.push(t);
		}
	}
	//pr2();
	if(q == n)
		return 1;
	return 0;
}
int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m))
	{
		if(!n && !m)
			return 0;
		int deter = 0, incon = 0;
		clear();
		for(int s = 0;s < m;s++)
		{
			char str[10];
			scanf("%s", str);
			if(deter || incon)
				continue;
			int u = str[0]-'A'+1, v = str[2]-'A'+1;
			incon = signal(u, v);
			if(incon)
			{
				printf("Inconsistency found after %d relations.\n", s+1);
				continue;
			}
			else
			{
				flag[u][v] = flag[u][0] = flag[v][0] = 1;
				g[u].push_back(v);
				rudu[v]++;
				deter = topo(n);
				if(deter)
				{
					printf("Sorted sequence determined after %d relations: ", s+1);
					for(int i = 0;i < q;i++)
						printf("%c", L[i]-1+'A');
					printf(".\n");
				}
			}
		}
		if(!deter && !incon)
			printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}