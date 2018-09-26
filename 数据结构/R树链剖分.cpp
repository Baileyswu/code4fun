/**************************************************

            模版：树链剖分
            题目：POJ3237 Tree

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define kl (k<<1)
#define kr ((k<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
const int maxn=10000+10, INF=0x7f7f7f7f;

int T, n;
int cur, fir[maxn], ver[maxn<<1], nxt[maxn<<1], cst[maxn<<1], eid[maxn<<1];
int tot, siz[maxn], son[maxn], dep[maxn], fa[maxn], fid[maxn], top[maxn], fw[maxn], idx[maxn], from[maxn];
struct node
{
	int mx, mn;
	bool f;
}tr[maxn<<2];

void Add(int u, int v, int c, int i)
{
	ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur, cst[cur]=c, eid[cur]=i;
	ver[++cur]=u, nxt[cur]=fir[v], fir[v]=cur, cst[cur]=c, eid[cur]=i;
	return ;
}

void Read()
{
	cur=0;
	memset(fir, 0, sizeof fir);
	scanf("%d", &n);
	for(int i=1, u, v, c; i<n; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		Add(u, v, c, i);
	}
	return ;
}

void Dfs1(int u, int f, int d)
{
	fa[u]=f, dep[u]=d, siz[u]=1;
	for(int i=fir[u], v, tmp=0; i; i=nxt[i]) if((v=ver[i])!=f)
	{
		fw[v]=cst[i], from[v]=eid[i];
		Dfs1(v, u, d+1);
		siz[u]+=siz[v];
		if(!son[u] || siz[v]>tmp)	son[u]=v, tmp=siz[v];
	}
	return ;
}

void Dfs2(int u, int tp)
{
	fid[u]=++tot, top[u]=tp;
	if(!son[u])	return ;
	Dfs2(son[u], tp);
	for(int i=fir[u], v; i; i=nxt[i]) if((v=ver[i])!=fa[u] && v!=son[u])	Dfs2(v, v);
	return ;
}

void Build(int k=1, int l=1, int r=n)
{
	tr[k].mx=-INF, tr[k].mn=INF, tr[k].f=false;
	if(l==r)	return ;
	Build(kl, l, mid);
	Build(kr, mid+1, r);
	return ;
}

void Init()
{
	memset(son, 0, sizeof son);
	Dfs1(1, 0, 1);

	tot=0;
	Dfs2(1, 1);
	return ;
}

inline void Ne(int k)
{
	tr[k].mx=-tr[k].mx, tr[k].mn=-tr[k].mn, tr[k].f^=1;
	swap(tr[k].mx, tr[k].mn);
	return ;
}

void Push_down(int k)
{
	if(tr[k].f)
	{
		Ne(kl);
		Ne(kr);
		tr[k].f=false;
	}
	return ;
}

void Push_up(int k)
{
	tr[k].mx=max(tr[kl].mx, tr[kr].mx);
	tr[k].mn=min(tr[kl].mn, tr[kr].mn);
	return ;
}

void Update(int x, int v, int k=1, int l=1, int r=n)
{
	if(l==r)
	{
		tr[k].mx=tr[k].mn=v, tr[k].f=false;
		return ;
	}
	Push_down(k);
	if(x<=mid)	Update(x, v, kl, l, mid);
	else Update(x, v, kr, mid+1, r);
	Push_up(k);
	return ;
}

int Query(int ll, int rr, int k=1, int l=1, int r=n)
{
	if(rr< l||r< ll)	return -INF;
	if(ll<=l&&r<=rr)	return tr[k].mx;
	Push_down(k);
	int tl=Query(ll, rr, kl, l, mid), tr=Query(ll, rr, kr, mid+1, r);
	Push_up(k);
	return max(tl, tr);
}

void Negate(int ll, int rr, int k=1, int l=1, int r=n)
{
	if(rr< l||r< ll)	return ;
	if(ll<=l&&r<=rr)
	{
		Ne(k);
		return ;
	}
	Push_down(k);
	Negate(ll, rr, kl, l, mid);
	Negate(ll, rr, kr, mid+1, r);
	Push_up(k);
	return ;
}

int Find(int u, int v)
{
	int ans=-INF, tu=top[u], tv=top[v], tmp;
	while(tu!=tv)
	{
		if(dep[tu]<dep[tv])	swap(tu, tv), swap(u, v);
		tmp=Query(fid[tu], fid[u]);
		ans=max(ans, tmp);
		u=fa[tu], tu=top[u];
	}
	if(u==v)	return ans;

	if(dep[u]>dep[v])	swap(u, v);
	tmp=Query(fid[son[u]], fid[v]);
	return max(ans, tmp);
}

void Change(int u, int v)
{
	int tu=top[u], tv=top[v];
	while(tu!=tv)
	{
		if(dep[tu]<dep[tv])	swap(tu, tv), swap(u, v);
		Negate(fid[tu], fid[u]);
		u=fa[tu], tu=top[u];
	}
	if(u==v)	return ;

	if(dep[u]>dep[v])	swap(u, v);
	Negate(fid[son[u]], fid[v]);
	return ;
}

void Work()
{
	Build();
	for(int i=2; i<=n; i++) Update(idx[from[i]]=fid[i], fw[i]);
	char s[10];
	while(scanf("%s", s)!=EOF&&s[0]!='D')
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(s[0]=='C')	Update(idx[a], b);
		else if(s[0]=='Q')	printf("%d\n", Find(a, b));
		else Change(a, b);
	}
	return ;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		Read();
		Init();
		Work();
	}
	return 0;
}
