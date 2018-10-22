#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, m, ans;
#define N 10100
std::vector<int> v[N];
int vis[N], dfn[N], low[N], stk[N], top, ins[N], clk;
void Tarjon(int x){
	dfn[x] = low[x] = clk++;
	stk[top++] = x;
	// printf("%d %d\n", x+1, clk);
	vis[x] = ins[x] = 1;
	for(int j = 0;j < v[x].size();j++){
		int y = v[x][j];
		if(!vis[y]){
			Tarjon(y);
			low[x] = min(low[x], low[y]);
		} else if(ins[y]){
			low[x] = min(low[x], dfn[y]);
		}
	}
	// printf("stk:");
	// for(int i = 0;i < top;i++)
		// printf("%d%c", stk[i]+1, " \n"[i==top-1]);
	if(low[x] == dfn[x]){
		int sz = 0;
		do {
			ins[stk[top-1]] = 0;
			// printf("pop %d\n", stk[top-1]+1);
			top--;
			sz++;
		} while(stk[top] != x);
		if(sz > 1) ans++;
	}
}
int main()
{
	while(~scanf("%d%d", &n, &m)){
		memset(v, 0, sizeof(v));
		for(int i = 0;i < m;i++){
			int x, y;scanf("%d%d", &x, &y);
			x--; y--;
			v[x].push_back(y);
		}
		memset(vis, 0, sizeof(vis));
		memset(ins, 0, sizeof(ins));
		top = ans = clk = 0;
		for(int i = 0;i < n;i++) if(!vis[i])
			Tarjon(i);
		// for(int i = 0;i < n;i++)
			// printf("%d %d %d\n", i+1, dfn[i]+1, low[i]+1);
		printf("%d\n", ans);
	}
	return 0;
}