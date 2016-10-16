#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int mn=22222;
const int mm=1000000;
const int oo=0x3fffffff;
int node, st, sd, edge, Edge;
int reach[mm], flow[mm], next[mm];
int head[mn], work[mn], dis[mn], que[mn];
int du[mm], ans[mm], id[mm], dn[mm];

inline void init(int _node, int _st, int _sd)
{
    node=_node, st=_st, sd=_sd;
    for(int i=0; i<node; i++)
        head[i]=-1;
    edge=0;
}

inline void addedge(int u, int v, int c1, int c2, int ID)
{
    id[edge]=ID, reach[edge]=v, flow[edge]=c1, next[edge]=head[u],head[u]=edge++;
    id[edge]=0, reach[edge]=u, flow[edge]=c2, next[edge]=head[v],head[v]=edge++;
}

bool bfs()
{
    int u, v, l=0, h=0;
    for(int i=0; i<node; i++) dis[i]=-1;
    que[l++]=st;
    dis[st]=0;
    while(l!=h)
    {
        u=que[h++];
        if(h==mn) h=0;
        for(int i=head[u]; i>=0; i=next[i])
        {
            v=reach[i];
            if(flow[i]&&dis[v]<0)
            {
                dis[v]=dis[u]+1;
                que[l++]=v;
                if(l==mn) l=0;
                if(v==sd) return true;
            }
        }
    }
    return false;
}

int dfs(int u, int exp)
{
    if(u==sd) return exp;
    for(int &i=work[u]; i>=0; i=next[i])
    {
        int v=reach[i], tp;
        if(flow[i]&&dis[v]==dis[u]+1&&(tp=dfs(v,min(flow[i],exp)))>0)
        {
            flow[i]-=tp;
            flow[i^1]+=tp;
            return tp;
        }
    }
    return 0;
}

void Dinic()
{
    while(bfs())
    {
        for(int i=0; i<node; i++) work[i]=head[i];
        while(dfs(st,oo));
    }
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init(n+2,0,n+1);
        for(int i=1; i<=m; i++)
        {
            int u, v, down, up;
            scanf("%d%d%d%d",&u,&v,&down,&up);
            addedge(u,v,up-down,0,i);
            du[u]-=down;
            du[v]+=down;
            dn[i]=down;
        }
        Edge=edge;
        for(int i=1; i<=n; i++)
        {
            if(du[i]>0) addedge(st,i,du[i],0,0);
            if(du[i]<0) addedge(i,sd,-du[i],0,0);
        }
        Dinic();
        bool flag=true;
        for(int i=head[st]; i>=0; i=next[i])
            if(flow[i]>0)
            {
                flag=false;
                break;
            }
        if(!flag) puts("NO");
        else
        {
            puts("YES");
            for(int i=0; i<Edge; i++) ans[id[i]]=flow[i^1];
            for(int i=1; i<=m; i++)
                printf("%d\n",ans[i]+dn[i]);
        }
    }
    return 0;
}