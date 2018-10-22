
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, m;
#define N 510
std::vector<int> v[N], w[N];
int vis[N], flag[N], out[N], ins[N], stk[N], dfn[N], low[N];
int sz, top, clk;

int mp[N][N];
void strong(int x){
	// printf("strong %d\n",  x);
	dfn[x] = low[x] = clk++;
	stk[top++] = x;
	ins[x] = vis[x] = 1;
	for(int j = 0;j < v[x].size();j++){
		int y = v[x][j];
		if(!vis[y]){
			strong(y);
			low[x] = min(low[x], low[y]);
		} else if(ins[y])
			low[x] = min(low[x], low[y]);
	}
	if(dfn[x] == low[x]){
		// printf("stk: sz=%d    x%d %d %d\n", sz, x, dfn[x], low[x]);
		do{
			// printf("%d (%d, %d)", stk[top-1], dfn[stk[top-1]], low[stk[top-1]]);
			flag[stk[top-1]] = sz;
			ins[stk[top-1]] = 0;
			top--;
		} while(stk[top] != x);
		sz++;
		// printf("\n");
	}
}
int p[N], nr[N][N];
void build(){
	// printf("build\n");
	memset(nr, 0, sizeof(nr));
	// for(int i = 0;i < n;i++)
	// 	printf("%d %d\n", i, flag[i]);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < v[i].size();j++){
			int y = v[i][j];
			if(flag[i] != flag[y]){
				w[flag[i]].push_back(flag[y]);
				nr[flag[i]][flag[y]] = mp[i][y];
				// printf("build %d %d %d\n", flag[i], flag[y], mp[i][y]);
			}
		}
	// for(int i = 0;i < sz;i++)
	 //	for(int j = 0;j < sz;j++)
 	//	if(nr[i][j])
				// printf("nr--- %d %d %d\n", i, j, nr[i][j]);
}
void init(){
	for(int i = 0;i < N;i++){
		w[i].clear();
		v[i].clear();
	}
	memset(vis, 0, sizeof(vis));
	memset(ins, 0, sizeof(ins));
	memset(out, 0, sizeof(out));
	memset(flag, 0, sizeof(flag));
	clk = top = sz = 0;
}

int ans[N];
#define MAXD 1000000000
struct node
{
	int num, cost;
	node(){}
	node(int x, int y){num = x, cost = y;}
	void pr(){
		printf("node %d %d\n", num, cost);
	}
};
priority_queue <node> Q;
bool operator<(node a, node b){
	return a.cost > b.cost;
}
int att[N][N];
int st(){
    for(int i = 0;i < sz;i++)
        for(int j =0;j <sz;j++){
            if(i==j)att[i][j]=0;
            else att[i][j] = nr[i][j]? nr[i][j]:MAXD;
        }
    //for(int k = 0;k < sz;k++)
    //    for(int i = 0;i < sz;i++)
      //      for(int j =0;j < sz;j++)
        //        att[i][j]=min(att[i][j],att[i][k]+att[k][j]);
}
int dis[N],INF=MAXD;
int dij(int st,int en)
{
	//memset(dis,INF,sizeof(dis));
for(int i=0;i<sz;i++)dis[i]=INF;
	memset(vis,0,sizeof(vis));
	dis[st] = 0;

	int p,m,tp=sz;
//printf("%d %d=>\n",st,en);
	while(1)
	{
		m = INF;
		p = -1;
		for(int i = 0; i < tp; ++i)
			if(!vis[i] && dis[i] < m)
			{
				m = dis[i];
				p = i;
			}
//printf("p=%d dis[p]=%d m=%d en=%d\n", p,  dis[p],  m,en);
		if(p == en) return dis[p];
		if(p == -1) return INF;
		vis[p] = 1;

		for(int i = 0; i < tp; ++i)
			if(!vis[i] && nr[p][i] && dis[i] > dis[p]+nr[p][i]){
//printf("%d %d nr %d\n", p, i, nr[p][i]);
				dis[i] = dis[p]+nr[p][i];
                 }
	}

}
int dij2(int x, int y){
	// printf("x y %d %d\n", x, y);
	// if(x == y) return 0;
	while(!Q.empty()) Q.pop();
	Q.push(node(x, 0));
	memset(vis, 0, sizeof(vis));
	for(int i = 0;i < sz;i++)
		ans[i] = MAXD;
	ans[x] = 0;
	while(!Q.empty()){
		node f = Q.top(); Q.pop();
		// f.pr();
		int l = f.num;if(vis[l])continue;
		vis[l] = 1;
		ans[l] = min(ans[l], f.cost);
		if(l == y) break;
		for(int j = 0;j < w[l].size();j++){
			int r = w[l][j];
			// printf("%d -> %d\n", l, r);
			if(!vis[r]){
				Q.push(node(r, ans[l]+nr[l][r]));
			}
		}
	}
	return ans[y];
}
int main()
{
	while(~scanf("%d%d", &n, &m)){
		if(!n && !m) break;
		init();
		memset(mp, 0, sizeof(mp));
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			v[x].push_back(y);
			scanf("%d", &mp[x][y]);
		}
		for(int i = 0;i < n;i++)
			if(!vis[i]) 
				strong(i);
		build();
		scanf("%d", &m);
//st();
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			int t = dij(flag[x], flag[y]);
//int t = att[flag[x]][flag[y]];
			if(t == MAXD) printf("Nao e possivel entregar a carta\n");
			else printf("%d\n", t);
		}
		printf("\n");
	}
	return 0;
}