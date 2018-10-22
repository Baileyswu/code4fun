#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 110
std::vector<int> v[N], w[N];
int in[N], out[N], clk[2*N], cnt, vis[N], fn, flag[N], n;
void dfs(int x){
	vis[x] = 1;
	clk[cnt++] = x;
	for(int j = 0;j < v[x].size();j++) if(!vis[v[x][j]])
		dfs(v[x][j]);
	clk[cnt++] = x;
}
void strong(int x, int f){
	// printf("%d %d\n", x, f);
	flag[x] = f;
	vis[x] = 1;
	for(int j = 0;j < w[x].size();j++) if(!vis[w[x][j]])
		strong(w[x][j], f);
}
void solve(){
	if(fn == 1){
		printf("0\n0\n");
		return;
	}
	for(int i = 0;i < n;i++)
		for(int j = 0;j < v[i].size();j++)
			if(flag[i] != flag[v[i][j]]){
				in[flag[v[i][j]]]++;
				out[flag[i]]++;
			}
	int a, b;
	a = b = 0;
	for(int i = 1;i <= fn;i++){
		if(in[i] == 0) a++;
		if(out[i] == 0) b++;
	}
	printf("%d\n%d\n", a, max(a, b));
}
int main()
{
	while(~scanf("%d", &n)){
		memset(v, 0, sizeof(v));
		memset(w, 0, sizeof(w));
		memset(vis, 0, sizeof(vis));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(flag, 0, sizeof(flag));
		for(int i = 0;i < n;i++){
			int u;
			while(scanf("%d", &u), u){
				u--;
				v[i].push_back(u);
				w[u].push_back(i);
			}
		}
		fn = cnt = 0;
		for(int i = 0;i < n;i++) 
			if(!vis[i])
				dfs(i);
		memset(vis, 0, sizeof(vis));
		// for(int i = 0;i < 2*n;i++)
			// printf("%d%c", clk[i], " \n"[i==2*n-1]);
		for(int i = 2*n-1;i >= 0;i--) {
			if(!vis[clk[i]])
				strong(clk[i], ++fn);
		}
		solve();
	}
	return 0;
}