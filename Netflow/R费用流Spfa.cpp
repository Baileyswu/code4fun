/**************************************************

            模版：费用流Spfa
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

int n, m, S, T, dis[maxn<<1], pre[maxn<<1], fro[maxn<<1];
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
    h=pp=0, cur=1;
    memset(fir, 0, sizeof fir);
    memset(pre, 0, sizeof pre);
    memset(fro, 0, sizeof fro);
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

bool Spfa()
{
    queue<int> q;
    memset(vis, false, sizeof vis);
    memset(dis, 0x7f, sizeof dis);
    dis[S]=0;
    q.push(S);
    vis[S]=true;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;

        for(int i=fir[u], v; i; i=nxt[i])
            if(cap[i]>0&&dis[v=ver[i]]>dis[u]+prc[i])
            {
                dis[v]=dis[u]+prc[i];
                pre[v]=u, fro[v]=i;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
    }

    return dis[T]!=INF;
}

void Work()
{
    int ans=0, delta=0;
    while(Spfa())
    {
        delta=INF;
        for(int u=T; u!=S; u=pre[u])    delta=min(delta, cap[fro[u]]);
        for(int u=T; u!=S; u=pre[u])    cap[fro[u]]-=delta, cap[fro[u]^1]+=delta;
        ans+=dis[T]*delta;
    }
    cout<<ans<<endl;
    return ;
}

int main()
{
    while(scanf("%d%d", &n, &m)!=EOF&&n+m)   Init(), Read(), Work();
    return 0;
}
