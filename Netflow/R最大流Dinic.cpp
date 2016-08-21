/**************************************************

            模版：最大流Dinic
            题目：HDU3549 Flow Problem
            
**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define Min(a, b) ((a)<(b)?(a):(b))
using namespace std;
const int maxn=15+5, maxm=1000+10, INF=0x7fffffff;

int T, n, m, st, des, rec[maxn], dis[maxn];
int cur, fir[maxn], ver[maxm<<1], nxt[maxm<<1], cap[maxm<<1];
bool vis[maxn];

void Add(int u, int v, int c)
{
    ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur, cap[cur]=c;
    ver[++cur]=u, nxt[cur]=fir[v], fir[v]=cur, cap[cur]=0;
    return ;
}

void Init()
{
    cur=1;
    memset(fir, 0, sizeof fir);
    return ;
}

void Read()
{
    scanf("%d%d", &n, &m);
    for(int i=1, u, v, c; i<=m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        Add(u, v, c);
    }
    st=1, des=n;
    return ;
}

bool Bfs()
{
    queue<int> q;
    memset(dis, 0, sizeof dis);
    memset(vis, false, sizeof vis);
    dis[st]=0, vis[st]=true;
    q.push(st);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        
        for(int i=fir[u], v; i; i=nxt[i])
            if(cap[i]>0&&!vis[v=ver[i]])
            {
                dis[v]=dis[u]+1, vis[v]=true;
                q.push(v);
                if(v==des)  return true;
            }
    }

    return false;
}

int Dfs(int u, int flow)
{
    if(u==des||!flow)   return flow;

    int rest=flow, del;
    for(int i=rec[u], v; i; i=nxt[i])
        if(dis[u]+1==dis[v=ver[i]]&&(del=Dfs(v, Min(rest, cap[i])))>0)
        {
            cap[i]-=del, cap[i^1]+=del, rest-=del;
            if(!rest)   break;
        }
    
    return flow-rest;
}

int Dinic()
{
    int ans=0;
    while(Bfs())
    {
        memcpy(rec, fir, sizeof fir);
        ans+=Dfs(st, INF);
    }
    return ans;
}

int main()
{
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        Init(), Read();
        printf("Case %d: %d\n", i, Dinic());
    }
    return 0;
}

