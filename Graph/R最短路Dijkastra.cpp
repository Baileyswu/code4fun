/**************************************************

            模版：最短路Dijkastra
            题目：HDU2544 最短路
            注意：针对正权图

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=100+10;

int n, m, d[maxn][maxn], s[maxn];
bool vis[maxn];

void Read()
{
    memset(s, 0xf, sizeof s);
    memset(d, 0xf, sizeof d);
    memset(vis, false, sizeof vis);

    for(int i=1, u, v, c; i<=m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        d[u][v]=d[v][u]=c;
    }
    return ;
}

void Work()
{
    int S=1, T=n, u=1, v, cur, cnt=0;
    s[S]=0;
    while(cnt++<n)
    {
        vis[u]=true;
        for(int i=1; i<=n; i++)
        {
            if(vis[i])  continue;
            if(s[i]>s[u]+d[u][i])    s[i]=s[u]+d[u][i];
            if(s[i]<cur)    cur=s[i], v=i;
        }
        u=v, cur=s[0];
    }
    printf("%d\n", s[T]);
    return ;
}

int main()
{
    while(scanf("%d%d", &n, &m)!=EOF&&n+m)   Read(), Work();
    return 0;
}
