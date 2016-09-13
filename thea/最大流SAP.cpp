/**************************************************

            模版：最大流SAP
            题目：HDU3549 Flow Problem
            
**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#define Min(a, b) ((a)<(b)?(a):(b))
using namespace std;
const int maxn=15+5, maxm=1000+10, INF=0x7fffffff;

int T, n, m, st, des, ans, d[maxn], vd[maxn];
int cur, fir[maxn], ver[maxm<<1], nxt[maxm<<1], cap[maxm<<1];

void Add(int u, int v, int c)
{
    ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur, cap[cur]=c;
    ver[++cur]=u, nxt[cur]=fir[v], fir[v]=cur, cap[cur]=0;
    return ;
}

void Init()
{
    cur=1;
    memset(d, 0, sizeof d);
    memset(vd, 0, sizeof vd);
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

int Aug(int u, int flow)
{
    if(u==des)  return flow;
    int rest=flow, mind=n-1, del;

    for(int i=fir[u], v; i; i=nxt[i])
        if(cap[i]>0)
        {
            if(d[u]==d[v=ver[i]]+1)
            {
                del=Aug(v, Min(rest, cap[i]));
                cap[i]-=del, cap[i^1]+=del, rest-=del;
                if(d[st]>=n)    return flow-rest;
                if(!rest)    break;
            }
            mind=Min(mind, d[v]);
        }

    if(rest==flow)
    {
        if(!--vd[d[u]]) d[st]=n;
        ++vd[d[u]=mind+1];
    }
    return flow-rest;
}

int Sap()
{
    ans=0, vd[0]=n;
    while(d[st]<n) ans+=Aug(st, INF);
    return ans;
}

int main()
{
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        Init(), Read();
        printf("Case %d: %d\n", i, Sap());
    }
    return 0;
}

