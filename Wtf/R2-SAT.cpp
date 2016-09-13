/**************************************************

            模版：2-SAT
            题目：POJ 3678 Katu Puzzle

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=2000+10, maxm=1000000+10;

int n, m, idx, dfn[maxn], low[maxn], tot, w[maxn];
int cur, fir[maxn], nxt[maxm<<1], ver[maxm<<1];
bool ins[maxn];
stack<int> stk;

void Init()
{
	cur=idx=tot=0;
	memset(w, 0, sizeof w);
	memset(fir, 0, sizeof fir);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(ins, false, sizeof ins);
	while(!stk.empty())	stk.pop();
	return ;
}

void Add(int u, int v)
{
	ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur;
	return ;
}

void Read()
{
	n<<=1;

	char s[10];
	for(int i=1, u, v, t; i<=m; i++)
	{
		scanf("%d%d%d%s", &u, &v, &t, s);
		u<<=1; v<<=1;
		switch(s[0])
		{
			case 'A':	if(t)	Add(u^1, u), Add(v^1, v);
						else Add(u, v^1), Add(v, u^1);
						break;
			case 'O':	if(t)	Add(u^1, v), Add(v^1, u);
						else Add(u, u^1), Add(v, v^1);
						break;
			case 'X':	if(t)	Add(u, v^1), Add(v, u^1), Add(u^1, v), Add(v^1, u);
						else Add(u, v), Add(v, u), Add(u^1, v^1), Add(v^1, u^1);
						break;
		}
	}
	return ;
}

void Tarjan(int u)
{
	dfn[u]=low[u]=++idx;
	ins[u]=true;
	stk.push(u);

	for(int i=fir[u], v; i; i=nxt[i])
	{
		if(!dfn[v=ver[i]])
		{
			Tarjan(v);
			low[u]=min(low[u], low[v]);
		}
		else if(ins[v])	low[u]=min(low[u], low[v]);
	}

	if(dfn[u]==low[u])
	{
		int v=stk.top();
		stk.pop();

		w[v]=++tot, ins[v]=false;
		while(v!=u)
		{
			v=stk.top();
			stk.pop();
			w[v]=tot, ins[v]=false;
		}
	}
	return ;
}

bool Ok()
{
	for(int i=0; i<n; i+=2)	if(w[i]==w[i^1])	return false;
	return true;
}

void Work()
{
	for(int i=0; i<n; i++)	if(!dfn[i])	Tarjan(i);
	if(Ok())	printf("YES\n");
	else printf("NO\n");
	return ;
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)	Init(), Read(), Work();
	return 0;
}
