/**************************************************

            模版：最小生成树Prim
            题目：POJ1258 Agri-Net

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=100+10;

int n, d[maxn][maxn], _min[maxn];
bool vis[maxn];

void Read()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &d[i][j]);
    return ;
}

void Work()
{
    memset(vis, false, sizeof vis);
    memset(_min, 0xf, sizeof _min);

    int u=1, v, cur=_min[0], cnt=1, ans=0; //任意找一个点加入集合
    while(cnt++<n)
    {
        vis[u]=true;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]||u==i)  continue;
            if(_min[i]>d[u][i]) _min[i]=d[u][i]; //更新邻接点到目标集合的最短距离
            if(_min[i]<cur) cur=_min[i], v=i; //取距离最近的点加入目标集合
        }
        u=v, ans+=cur, cur=_min[0];
    }

    printf("%d\n", ans);
    return ;
}

int main()
{
    while(scanf("%d", &n)!=EOF) Read(), Work();
    return 0;
}
