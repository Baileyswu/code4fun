#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, m;
#define N 31000
std::vector<int> v[N], w[N];
int vis[N], flag[N], in[N], ins[N], stk[N], dfn[N], low[N], a[N], b[N], c[N];
int sz, top, clk;

void Tarjon(int x){
	dfn[x] = low[x] = clk++;
	stk[top++] = x;
	ins[x] = vis[x] = 1;
	for(int j = 0;j < v[x].size();j++){
		int y = v[x][j];
		if(!vis[y]){
			Tarjon(y);
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
			b[sz] += a[stk[top-1]]; 
			// printf("b-- %d %d\n", sz, b[sz]);
			top--;
		} while(stk[top] != x);
		sz++;
		// printf("\n");
	}
}

void solve(){
	for(int i = 0;i < n;i++)
		for(int j = 0;j < v[i].size();j++){
			int y = v[i][j];
			if(flag[i] != flag[y]){
				in[flag[y]]++;
				w[flag[i]].push_back(flag[y]);
			}
		}
	// for(int i = 0;i < n;i++)
		// printf("%d %d %d\n", i, flag[i], in[flag[i]]);
	int r = 0, ans = 0;
	memset(vis, 0, sizeof(vis));
	memset(c, 0, sizeof(c));
	while(r < sz){
		for(int i = 0;i < sz;i++) if(!vis[i] && in[i] == 0){
			// printf("top i = %d %d %d\n", i, b[i], c[i]);
			vis[i] = 1; r++;
			// printf("%d %d\n", ans, b[i]+c[i]);
			ans = max(ans, b[i]+c[i]);
			for(int j = 0;j < w[i].size();j++){
				int y = w[i][j];
				in[y]--;
				c[y] = max(c[y], b[i]+c[i]);
			}
		}
	}
	printf("%d\n", ans);
}
void init(){
	for(int i = 0;i < N;i++){
		w[i].clear();
		v[i].clear();
	}
	memset(vis, 0, sizeof(vis));
	memset(ins, 0, sizeof(ins));
	memset(in, 0, sizeof(in));
	memset(b, 0, sizeof(b));
	memset(flag, 0, sizeof(flag));
	clk = top = sz = 0;
}
int main()
{
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0;i < n;i++){
			scanf("%d", &a[i]);
			a[i] = max(0, a[i]);
		}
		init();
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
		}
		for(int i = 0;i < n;i++) if(!vis[i])
			Tarjon(i);
		solve();
	}
	return 0;
}