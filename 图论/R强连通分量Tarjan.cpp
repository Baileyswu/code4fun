/**************************************************

            模版：Tarjan
            题目：POJ1236 Network of Schools
            
**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=100+10;

int n, ans1, ans2, tot, w[maxn];
int cur, fir[maxn], nxt[maxn*maxn], ver[maxn*maxn];
int idx, dfn[maxn], low[maxn];
bool ins[maxn], in[maxn], out[maxn];
stack<int> s;

void Add(int x, int y)
{
    ver[++cur]=y, nxt[cur]=fir[x], fir[x]=cur;
    return ;
}

void Tarjan(int u)
{
    dfn[u]=low[u]=++idx;
    ins[u]=true;
    s.push(u);

    for(int i=fir[u], v; i; i=nxt[i])
        if(!dfn[v=ver[i]])
        {
            Tarjan(v);
            low[u]=Min(low[u], low[v]);
        }
        else if(ins[v]) low[u]=Min(low[u], low[v]);//low[u]=Min(low[u], dfn[v])所得结果不同 但dfn[v]和low[v]均小于low[u]
                                                   //算法只在乎dfn[u]==low[u]的节点
                                                   //所以任何一种写法对整体结果都不影响

    if(dfn[u]==low[u])
    {
        int v=s.top();
        s.pop();

        w[v]=++tot, ins[v]=false;
        while(v!=u)
        {
            v=s.top();
            s.pop();
            w[v]=tot, ins[v]=false;
        }
    }
    return ;
}

int main()
{
    scanf("%d", &n);
    for(int i=1, j; i<=n; i++)  while(scanf("%d", &j)&&j)   Add(i, j);
    
    for(int i=1; i<=n; i++) if(!dfn[i]) Tarjan(i);
    
    for(int i=1; i<=n; i++)
        for(int k=fir[i], j; k; k=nxt[k])
        {
            if(w[i]==w[j=ver[k]])   continue;
            in[w[j]]=out[w[i]]=true;
        }

    for(int i=1; i<=tot; i++)   ans1+=(!in[i]), ans2+=(!out[i]);

    if(tot==1)  printf("1\n0\n");
    else printf("%d\n%d\n", ans1, Max(ans1, ans2));
    return 0;
}
