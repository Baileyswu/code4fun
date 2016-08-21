/**************************************************

            模版：费用流Zkw
            题目：POJ2195 Going Home
            
**************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100+10, maxm=20000+10, INF=0x7f7f7f7f;

int n, m, S, T, ans, dis[maxn<<1], pre[maxn<<1], fro[maxn<<1];
int h, hx[maxn], hy[maxn], pp, px[maxn], py[maxn];
int cur, fir[maxn<<1], ver[maxm<<1], nxt[maxm<<1], cap[maxm<<1], prc[maxm<<1];
bool vis[maxn<<1];
char s[maxn][maxn];

int Dis(int u, int v)
{
    return abs(hx[u]-px[v])+abs(hy[u]-py[v]);
}

void Add(int u, int v, int c, int p)
{
    ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur, cap[cur]=c, prc[cur]=p;
    ver[++cur]=u, nxt[cur]=fir[v], fir[v]=cur, cap[cur]=0, prc[cur]=-p;
    return ;
}

void Init()
{
    ans=h=pp=0, cur=1;
    memset(fir, 0, sizeof fir);
    memset(pre, 0, sizeof pre);
    memset(fro, 0, sizeof fro);
    memset(dis, 0, sizeof dis);
    return ;
}

void Read()
{
    for(int i=1; i<=n; i++) scanf("%s", s[i]+1);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(s[i][j]=='H')    hx[++h]=i, hy[h]=j;
            else if(s[i][j]=='m')   px[++pp]=i, py[pp]=j;
        }

    S=0, T=h+pp+1;
    for(int i=1; i<=h; i++) Add(S, i, 1, 0);
    for(int i=1; i<=h; i++)
        for(int j=1; j<=pp; j++)
            Add(i, j+h, 1, Dis(i, j));
    for(int i=1; i<=pp; i++) Add(i+h, T, 1, 0);
    return ;
}

int Aug(int u, int flow)
{
    if(u==T)
    {
        ans+=flow*dis[S];
        return flow;
    }

    vis[u]=true;
    int rest=flow, delta=0;

    for(int i=fir[u], v; i; i=nxt[i])
        if(!vis[v=ver[i]]&&cap[i]>0&&dis[u]==dis[v]+prc[i])
        {
            delta=Aug(v, min(cap[i], rest));
            cap[i]-=delta, cap[i^1]+=delta, rest-=delta;
            if(!rest)   break;
        }

    return flow-rest;
}

bool Update()
{
    int delta=INF;
    for(int u=S; u<=T; u++) if(vis[u])
        for(int i=fir[u], v; i; i=nxt[i])
            if(cap[i]>0&&!vis[v=ver[i]])
                delta=min(delta, dis[v]-dis[u]+prc[i]);
    if(delta==INF)  return false;
    for(int u=S; u<=T; u++) if(vis[u])  dis[u]+=delta;
    return true;
}

void Zkw()
{
    do
    {
        do{ memset(vis, false, sizeof vis); }while(Aug(S, INF));
    }while(Update());
    cout<<ans<<endl;
    return ;
}

int main()
{
    while(scanf("%d%d", &n, &m)!=EOF&&n+m)   Init(), Read(), Zkw();
    return 0;
}
