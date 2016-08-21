/**************************************************

            模版：最大流EK
            题目：HDU3549 Flow Problem
            
**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define Min(a, b) ((a)<(b)?(a):(b))
using namespace std;
const int maxn=15+5, maxm=1000+10, INF=0x7fffffff;

int T, n, m, st, des;
int cur, fir[maxn], ver[maxm<<1], nxt[maxm<<1], cap[maxm<<1];
int pre[maxn], rec[maxn], flow[maxn];
queue<int> q;

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

int Bfs()
{
    while(!q.empty())   q.pop();
    memset(pre, -1, sizeof pre);
    pre[st]=0, flow[st]=INF;
    q.push(st);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==des)  break;
        
        for(int i=fir[u], v; i; i=nxt[i])
            if(pre[v=ver[i]]==-1&&cap[i]>0)
            {
                pre[v]=u;
                rec[v]=i;
                flow[v]=Min(flow[u], cap[i]);
                q.push(v);
            }
    }

    return (pre[des]==-1)?(pre[des]):(flow[des]);
}

int Work()
{
    int ans=0, del=0;
    while((del=Bfs())!=-1)
    {
        for(int i=des; i!=st; i=pre[i]) cap[rec[i]]-=del, cap[rec[i]^1]+=del;
        ans+=del;
    }
    return ans;
}

int main()
{
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        Init(), Read();
        printf("Case %d: %d\n", i, Work());
    }
    return 0;
}
