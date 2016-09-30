/**************************************************

            模版：曼哈顿最小生成树
            题目：POJ 3241 Object Clustering

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define lowbit(x) ((x)&-(x))
using namespace std;
const int maxn=100000+10, INF=0x7f7f7f7f;

int n, m, cur, fa[maxn], a[maxn], b[maxn];
int val[maxn], pos[maxn], ans[maxn];
struct node
{
	int x, y, id;
	bool operator <(const node&t)const
	{
		return x==t.x?y<t.y:x<t.x;
	}
}p[maxn], pp[maxn];
struct line
{
	int u, v, d;
	line(int _u=0, int _v=0, int _d=0)
	{
		u=_u, v=_v, d=_d;
	}
	bool operator <(const line&t)const
	{
		return d<t.d;
	}
}s[maxn];

int Dist(node u, node v)
{
	return abs(u.x-v.x)+abs(u.y-v.y);
}

void Add(int u, int v, int d)
{
	s[++cur]=line(u, v, d);
	return ;
}

void Update(int x, int _val, int _pos)
{
	for(int i=x; i; i-=lowbit(i)) if(_val<val[i])
	{
		val[i]=_val;
		pos[i]=_pos;
	}
	return ;
}

int Query(int x, int N, int _val=INF, int _pos=0)
{
	for(int i=x; i<=N; i+=lowbit(i)) if(val[i]<_val)
	{
		_val=val[i];
		_pos=pos[i];
	}
	return _pos;
}

int Rt(int x)
{
	return x==fa[x] ? x : fa[x]=Rt(fa[x]);
}

void Manhattan()
{
	cur=0;
	int a[maxn], b[maxn];
	for(int d=0; d<4; d++)
	{
		if(d==1 || d==3)
		{
			for(int i=1; i<=n; i++)	swap(p[i].x, p[i].y);
		}
		else if(d==2)
		{
			for(int i=1; i<=n; i++)	p[i].x=-p[i].x;
		}
		sort(p+1, p+1+n);

		for(int i=1; i<=n; i++)	a[i]=b[i]=p[i].y-p[i].x;
		sort(b+1, b+1+n);
		int N=unique(b+1, b+1+n)-(b+1);
		for(int i=1; i<=N; i++)	val[i]=INF, pos[i]=0;

		for(int i=n; i; i--)
		{
			a[i]=lower_bound(b+1, b+1+N, a[i])-b;
			int ret=Query(a[i], N);
			if(ret)	Add(p[i].id, p[ret].id, Dist(p[i], p[ret]));
			Update(a[i], p[i].x+p[i].y, i);
		}
	}

	sort(s+1, s+1+cur);
	for(int i=1; i<=n; i++)	fa[i]=i;

	int cnt=1, i=0, u, v, d;
	while(cnt<n)
	{
		while(++i<=cur)
		{
			u=Rt(s[i].u), v=Rt(s[i].v), d=s[i].d;
			if(u!=v)	break;
		}
		ans[cnt++]=d;
		if(u<v)	fa[v]=u;
		else fa[u]=v;
	}

	printf("%d\n", ans[n-m]);
	return ;
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].id=i, pp[i]=p[i];
		}
		Manhattan();
	}
	return 0;
}
