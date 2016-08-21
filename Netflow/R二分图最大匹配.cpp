/**************************************************

            模版：二分图最大匹配
            题目：POJ1274 The Perfect Stall
            
**************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=200+10;

int n, m, ans, from[maxn];
int cur, fir[maxn], ver[maxn*maxn], nxt[maxn*maxn];
bool vis[maxn];

void Add(int u, int v)
{
	ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur;
	return ;
}

bool Dfs(int u)
{
	for(int i=fir[u], v; i; i=nxt[i])
	{
		if(vis[v=ver[i]])   continue;
		vis[v]=true;//保证y部每个结点不被重复访问

		if((!from[v])||Dfs(from[v]))//找到新结点 或从已匹配结点出发原路返回能找到新结点 则原路径反向 长度一定增加
		{
			from[v]=u;//记录y部每个结点与x部结点配对情况
			return true;
		}
	}
	return false;
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		cur=0, ans=0;
		memset(fir, 0, sizeof fir);
		memset(from, 0, sizeof from);

		for(int u=1, v, k; u<=n; u++)
		{
			scanf("%d", &k);
			for(int i=1; i<=k; i++)
			{
				scanf("%d", &v);
				Add(u, v);
			}
		}

		for(int i=1; i<=n; i++)
		{
			memset(vis, 0, sizeof vis);
			ans+=Dfs(i);//寻找增广路，保证每次增广成功时路径长度加一
		}

		cout<<ans<<endl;
	}
	return 0;
}
