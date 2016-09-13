/**************************************************

            模版：最小生成树Kuskal
            题目：POJ1258 Agri-Net

**************************************************/

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=100+10;

int n, fa[maxn], d[maxn][maxn];
struct node
{
    int u, v, c;
    bool operator <(const node&a)const { return c>a.c; }
}p;
priority_queue<node> q;

void Read()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &d[i][j]);

    while(!q.empty())   q.pop();
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
        {
            p.u=i, p.v=j, p.c=d[i][j];
            q.push(p);
        }
    return ;
}

int Rt(int x)
{
    return (x==fa[x])?(x):(fa[x]=Rt(fa[x]));
}

void Work()
{
    for(int i=1; i<=n; i++) fa[i]=i;

    int ans=0, cnt=1;
    while(cnt<n)
    {
        int u=Rt(q.top().u), v=Rt(q.top().v), c=q.top().c; //每次选最短边
        q.pop();
        if(u==v)    continue; //如果端点已经在同一集合 不更新
        ++cnt, ans+=c; //加入生成树
        if(u<v) fa[v]=u; //合并端点
        else fa[u]=v;
    }

    printf("%d\n", ans);
    return ;
}

int main()
{
    while(scanf("%d", &n)!=EOF) Read(), Work();
    return 0;
}
