#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, m, ans;
#define N 1010
std::vector<int> v[N], w[N];
int vis[N], dfn[N], low[N], stk[N], top, ins[N], clk, in[N], flag[N], fn;
void Tarjon(int x){
	dfn[x] = low[x] = clk++;
	stk[top++] = x;
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
	if(low[x] == dfn[x]){
		fn++;
		do {
			flag[stk[top-1]] = fn;
			ins[stk[top-1]] = 0;
			top--;
		} while(stk[top] != x);
		ans++;
	}
}
int cnt;
int dfs(int x){
	// printf("dfs %d\n", x);
	vis[x] = 1;
	cnt++;
	for(int j = 0;j < w[x].size();j++) 
		in[w[x][j]]--;
	int p = -1, s = 0;
	for(int i = 1;i <= fn;i++)
		if(!vis[i] && in[i] == 0){
			s++; p = i;
		}
	return s > 1 || p == -1 || dfs(p);
}
bool solve(){
	memset(w, 0, sizeof(w));
	memset(in, 0, sizeof(in));
	memset(vis, 0, sizeof(vis));
	// for(int i = 0;i < n;i++)
		// printf("%d %d\n", i, flag[i]);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < v[i].size();j++){
			int x = v[i][j];
			if(flag[x] != flag[i]){
				w[flag[i]].push_back(flag[x]);
				in[flag[x]]++;
			}
		}
	cnt = 0;
	int p = -1, s = 0;
	for(int i = 1;i <= fn;i++)
		if(in[i] == 0){
			s++; p = i;
		}
	if(s > 1 || p == -1) return false;
	dfs(p);
	return cnt == fn;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		memset(v, 0, sizeof(v));
		for(int i = 0;i < m;i++){
			int x, y;scanf("%d%d", &x, &y);
			x--; y--;
			v[x].push_back(y);
		}
		memset(vis, 0, sizeof(vis));
		memset(ins, 0, sizeof(ins));
		memset(flag, 0, sizeof(flag));
		fn = top = ans = clk = 0;
		for(int i = 0;i < n;i++) if(!vis[i])
			Tarjon(i);
		if(solve()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}