/**************************************************

            模版：二分图最佳匹配
            题目：POJ2195 Going Home
            
**************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100+10;
const int INF=0x7f7f7f7f;

int n, m, ch, cm;
int lx[maxn*maxn], ly[maxn], w[maxn*maxn][maxn], from[maxn], del;
bool vx[maxn*maxn], vy[maxn];
struct node
{
	int x, y;
	node(int a=0, int b=0){ x=a, y=b; }
}ph[maxn], pm[maxn*maxn];

int Dis(int a, int b)
{
	return abs(pm[a].x-ph[b].x)+abs(pm[a].y-ph[b].y);
}

bool Dfs(int x)
{
	vx[x]=true;
	for(int y=1; y<=ch; y++)
	{
		if(vy[y])   continue;

		int t=lx[x]+ly[y]-w[x][y];//对于每一条匹配中的边(u, v)，满足lx[u]+ly[v]>=w[u][v]
		if(!t)
		{
			vy[y]=true;
			if((!from[y])||Dfs(from[y]))
			{
				from[y]=x;
				return true;
			}
		}
		else if(del>t)  del=t;
	}
	return false;
}

int KM()
{
	for(int i=1; i<=cm; i++)//x部
	{
		while(true)
		{
			memset(vx, 0, sizeof vx);
			memset(vy, 0, sizeof vy);
			del=INF;
			if(Dfs(i))  break;
			for(int j=1; j<=cm; j++)  if(vx[j])   lx[j]-=del;
			for(int j=1; j<=ch; j++)  if(vy[j])   ly[j]+=del;//每一次修改lx[]、ly[]时
															 //端点均在/不在现有子图中的边不受影响
															 //x端在子图中的边，lx[u]'+ly[v]<lx[u]+ly[v]<w[u][v]，仍然不进入子图
															 //y端在子图中的边，lx[u]+ly[v]'>lx[u]+ly[v]，有可能进入子图
		}
	}

	int ans=0;
	for(int i=1; i<=ch; i++)    if(from[i])    ans+=w[from[i]][i];
	return ans;
}

int main()
{
	int T=0;
	while(scanf("%d%d", &n, &m)!=EOF&&n+m)
	{
		ch=cm=0;
		memset(ly, 0, sizeof ly);
		memset(from, 0, sizeof from);
		char s[maxn];

		for(int i=1; i<=n; i++)
		{
			scanf("%s", s+1);
			for(int j=1; j<=m; j++)
			{
				if(s[j]=='H')   ph[++ch]=node(i, j);
				else if(s[j]=='m')  pm[++cm]=node(i, j);
			}
		}

		for(int i=1; i<=cm; i++)
		{
			lx[i]=-INF;
			for(int j=1; j<=ch; j++)
			{
				w[i][j]=-Dis(i, j);
				lx[i]=min(lx[i], w[i][j]);//lx[i]：i结点相连边的最小权值
			}
		}

		cout<<-KM()<<endl;
	}
	return 0;
}
