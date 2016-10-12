/**
LCA在线算法O(nlogn)
主函数调用：
init();
tot=0,dir[1]=0;
dfs(1,1);
ST(2*n-1);
int lca=LCA(u,v);
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;
const int maxn=40010;///节点数目
const int maxm=25;
 
int _pow[maxm],m,n;///预处理2的幂
int head[maxn],ip;
int ver[maxn*2],R[maxn*2],first[maxn],dir[maxn],dp[maxn*2][maxm],tot;
///数组依次表示第u位置对应的节点存储、第x位置节点深度存储、第一次访问时间、到根节点的距离，RNQ数组，tot点依次访问标记
bool vis[maxn];
 
void init()
{
    memset(vis,false,sizeof(vis));
    memset(head,-1,sizeof(head));
    ip=0;
}
 
struct note
{
    int v,w,next;
}edge[maxn*2];
 
void addedge(int u,int v,int w)
{
    edge[ip].v=v,edge[ip].w=w,edge[ip].next=head[u],head[u]=ip++;
}
 
void dfs(int u,int dep)
{
    vis[u]=true;
    ver[++tot]=u,first[u]=tot,R[tot]=dep;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        int w=edge[i].w;
        if(!vis[v])
        {
            dir[v]=dir[u]+w;
            dfs(v,dep+1);
            ver[++tot]=u,R[tot]=dep;
        }
    }
}
 
void ST(int len)///RMQ预处理
{
    int k=(int)log((double)len)/(log(2.0));
    for(int i=1;i<=len;i++)
    {
        dp[i][0]=i;
    }
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i+_pow[j]-1<=len;i++)
        {
            int a=dp[i][j-1],b=dp[i+_pow[j-1]][j-1];
            if(R[a]<r[b]) a="dp[x][k],b=dp[y-_pow[k]+1][k];" else="" int="" k="(int)log((double)(y-x+1)/log(2.0));" lca="" return="" x="">y)swap(x,y);
    int res=RMQ(x,y);
    return ver[res];
}

/**
LCA（离线算法）
主函数除建边外还应调用
init();
dir[1]=0;
tarjan(1);
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn=40010;
 
struct note
{
    int u,v,w,lca,next;
}edge[maxn*2],edge1[805];
 
int head[maxn],ip,head1[maxn],ip1;///需要建两次边。1，该树的边2，需要查询的两点
int m,n;
int father[maxn],vis[maxn],dir[maxn];
///依次表示u点的祖先、标记是否访问过，到根节点的距离
 
void init()
{
    memset(vis,0,sizeof(vis));
    memset(dir,0,sizeof(dir));
    memset(head,-1,sizeof(head));
    memset(head1,-1,sizeof(head1));
    ip=ip1=0;
}
 
void addedge(int u,int v,int w)
{
    edge[ip].v=v,edge[ip].w=w,edge[ip].next=head[u],head[u]=ip++;
}
 
void addedge1(int u,int v)
{
    edge1[ip1].u=u,edge1[ip1].v=v,edge1[ip1].lca=-1,edge1[ip1].next=head1[u],head1[u]=ip1++;
}
 
int  Find(int x)
{
    if(father[x]==x)
        return x;
    return father[x]=Find(father[x]);
}
 
void Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(x!=y)
        father[y]=x;
}
 
void tarjan(int u)
{
    vis[u]=1;
    father[u]=u;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        int w=edge[i].w;
        if(!vis[v])
        {
           dir[v]=dir[u]+w;
           tarjan(v);
           Union(u,v);
        }
    }
    for(int i=head1[u];i!=-1;i=edge1[i].next)
    {
        int v=edge1[i].v;
        if(vis[v])
        {
            edge1[i].lca=edge1[i^1].lca=father[Find(v)];
        }
    }
}
