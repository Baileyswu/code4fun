/**************************************************

            模版：最短路SPFA
            题目：HDU2544 最短路
            tips：可用于负权图

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=100+10;

int n, m, S, T, d[maxn][maxn], s[maxn];
bool vis[maxn];
queue<int> q;

void Read()
{
    memset(d, 0xf, sizeof d);
    memset(s, 0xf, sizeof s);
    for(int i=1, u, v, c; i<=m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        d[u][v]=d[v][u]=c;
    }
    return ;
}

void Work()
{
    s[S=1]=0, T=n;

    q.push(S), vis[S]=true;
    
    while(!q.empty())
    {
        int u=q.front();

        for(int i=1; i<=n; i++)
            if(s[i]>s[u]+d[u][i])
            {
                s[i]=s[u]+d[u][i];
                if(!vis[i]) q.push(i), vis[i]=true;
            }
        
        q.pop(), vis[u]=false;
    }

    printf("%d\n", s[T]);
    return ;
}

int main()
{
    while(scanf("%d%d", &n, &m)!=EOF&&n+m)   Read(), Work();
    return 0;
}

