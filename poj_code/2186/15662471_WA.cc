#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define N 10100
std::vector<int> v[N], w[N];
int vis[N], a[2*N], flag[N], clk, tuan[N], out[N], fn, n, m;
void dfs(int x){
	vis[x] = 1;
	a[clk++] = x;
	for(int j = 0;j < v[x].size();j++)
		if(!vis[v[x][j]])
			dfs(v[x][j]);
	a[clk++] = x;
}
void strong(int x, int f){
	// printf("strong %d %d\n", x, f);
	vis[x] = 1;
	flag[x] = f;
	tuan[f]++;
	for(int j = 0;j < w[x].size();j++)
		if(!vis[w[x][j]])
			strong(w[x][j], f);
}
void solve(){
	memset(out, 0, sizeof(out));
	for(int i = 0;i < n;i++) if(v[i].size())
		out[flag[i]]++;
	int ans = 0, cc = 0;
	for(int i = 1;i <= fn;i++){
		// printf("out[f %d] = %d\n",i, out[i] );
		if(out[i] == 0){
			ans = i;
			cc++;
		}
	}
	// printf("%d %d\n", ans, cc);
	if(cc > 1) ans = 0;
	else ans = tuan[ans];
	printf("%d\n", ans);
}
int main()
{
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0;i < n;i++){
			v[i].clear();
			w[i].clear();
		}
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		memset(flag, 0, sizeof(flag));
		memset(tuan, 0, sizeof(tuan));
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			v[x].push_back(y);
			w[y].push_back(x);
		}
		clk = 0;
		for(int i = 0;i < n;i++){
			if(vis[i]) continue;
			dfs(i);
		}
		memset(vis, 0, sizeof(vis));
		fn = 0;
		// for(int i = 0;i < 2*n;i++)
			// printf("%d%c", a[i]+1, " \n"[i==2*n-1]);
		for(int i = 2*n-1;i >= 0;i--) 
			if(!vis[a[i]])
				strong(a[i], ++fn);
		// printf("fn = %d\n", fn);
		// for(int i = 0;i < n;i++)
			// printf("flag %d = %d\n", i, flag[i]);
		solve();
	}
	return 0;
}
