/**************************************************

            模版：莫队曼哈顿
            题目：LYDSY 2038 小Z的袜子(hose)

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#define lowbit(x) ((x)&-(x))
using namespace std;
typedef long long lint;
const int maxn=500000+10, INF=0x7f7f7f7f;

int n, m, col[maxn], tot, fa[maxn], c[maxn];
int val[maxn], pos[maxn];
int cur, fir[maxn], ver[maxn<<1], nxt[maxn<<1];
bool vis[maxn];

struct node
{
       	int l, r, id;
       	lint ans;
       	bool operator <(const node&t)const
       	{
       		return l==t.l ? r<t.r : l<t.l;
       	}
}p[maxn];
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

bool Cmp(node a, node b)
{
       	return a.id<b.id;
}

lint Gcd(lint a, lint b)
{
       	return b==0ll ? a : Gcd(b, a%b);
}

int Dist(node u, node v)
{
       	return abs(u.l-v.l)+abs(u.r-v.r);
}

void Line(int u, int v, int d)
{
       	s[++tot]=line(u, v, d);
       	return ;
}

int Rt(int x)
{
       	return x==fa[x] ? x : fa[x]=Rt(fa[x]);
}

void Add(int u, int v)
{
       	ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur;
       	ver[++cur]=u, nxt[cur]=fir[v], fir[v]=cur;
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

int Query(int x, int M, int _val=INF, int _pos=0)
{
       	for(int i=x; i<=M; i+=lowbit(i)) if(val[i]<_val)
       	{
       		_val=val[i];
       		_pos=pos[i];
       	}
       	return _pos;
}

void Manhattan()
{
       	tot=0;
       	int a[maxn], b[maxn];
       	for(int d=0; d<4; d++)
       	{
       		if(d==1 || d==3)
       		{
       			for(int i=1; i<=m; i++)	swap(p[i].l, p[i].r);
       		}
       		else if(d==2)
       		{
       			for(int i=1; i<=m; i++)	p[i].l=-p[i].l;
       		}
       		sort(p+1, p+1+m);

       		for(int i=1; i<=m; i++)	a[i]=b[i]=p[i].r-p[i].l;
       		sort(b+1, b+1+m);
       		int M=unique(b+1, b+1+m)-(b+1);
       		for(int i=1; i<=M; i++)	val[i]=INF, pos[i]=0;

       		for(int i=m; i; i--)
       		{
       			a[i]=lower_bound(b+1, b+1+M, a[i])-b;
       			int ret=Query(a[i], M);
       			if(ret)	Line(p[i].id, p[ret].id, Dist(p[i], p[ret]));
       			Update(a[i], p[i].l+p[i].r, i);
       		}
       	}

       	cur=0;
       	sort(s+1, s+1+tot);
       	for(int i=1; i<=m; i++) fa[i]=i;

       	int cnt=1, i=0, u, v, d;
       	while(cnt++<m)
       	{
       		while(++i<=tot)
       		{
       			u=Rt(s[i].u), v=Rt(s[i].v), d=s[i].d;
       			if(u!=v)       	break;
       		}
       		(u<v) ? fa[v]=u : fa[u]=v;
       		Add(s[i].u, s[i].v);
       	}
       	return ;
}

void Del(int l, int r, lint &tmp)
{
       	for(int i=l; i<=r; i++)	tmp-=2ll*(--c[col[i]]);
       	return ;
}

void Ins(int l, int r, lint &tmp)
{
       	for(int i=l; i<=r; i++)	tmp+=2ll*(c[col[i]]++);
       	return ;
}

void Dfs(int u, lint tmp)
{
       	vis[u]=true;

       	for(int i=fir[u], v; i; i=nxt[i])
       	{
       		if(vis[v=ver[i]])      	continue;

       		if(p[u].l<p[v].l)      	Del(p[u].l, p[v].l-1, tmp);
       		if(p[u].l>p[v].l)      	Ins(p[v].l, p[u].l-1, tmp);
       		if(p[u].r>p[v].r)      	Del(p[v].r+1, p[u].r, tmp);
       		if(p[u].r<p[v].r)      	Ins(p[u].r+1, p[v].r, tmp);

       		p[v].ans=tmp;
       		Dfs(v, tmp);

       		if(p[u].l<p[v].l)      	Ins(p[u].l, p[v].l-1, tmp);
       		if(p[u].l>p[v].l)      	Del(p[v].l, p[u].l-1, tmp);
       		if(p[u].r>p[v].r)      	Ins(p[v].r+1, p[u].r, tmp);
       		if(p[u].r<p[v].r)      	Del(p[u].r+1, p[v].r, tmp);
       	}

       	return ;
}

void Work()
{
       	sort(p+1, p+1+m, Cmp);
       	memset(vis, false, sizeof vis);
       	memset(c, 0, sizeof c);
       	for(int i=1; i<=m; i++) p[i].r=-p[i].r;

       	p[1].ans=0ll;
       	Ins(p[1].l, p[1].r, p[1].ans);
       	Dfs(1, p[1].ans);

       	for(int i=1; i<=m; i++)
       	{
       		if(p[i].ans==0ll || p[i].l==p[i].r)    	printf("0/1\n");
       		else
       		{
       			lint len=(p[i].r-p[i].l+1ll)*(p[i].r-p[i].l);
       			lint tmp=Gcd(p[i].ans, len);
       			printf("%lld/%lld\n", p[i].ans/tmp, len/tmp);
       		}
       	}
       	return ;
}

int main()
{
       	while(scanf("%d%d", &n, &m)!=EOF)
       	{
       		for(int i=1; i<=n; i++)	scanf("%d", &col[i]);
       		for(int i=1; i<=m; i++)
       		{
       			scanf("%d%d", &p[i].l, &p[i].r);
       			p[i].id=i;
       		}
       		Manhattan();
       		Work();
       	}
       	return 0;
}
