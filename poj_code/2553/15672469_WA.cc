#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, m;
#define N 5100
std::vector<int> v[N];
int vis[N], flag[N], out[N], ins[N], stk[N], dfn[N], low[N];
int sz, top;
void strong(int x){
	// printf("strong %d\n",  x);
	dfn[x] = low[x] = stk[top++] = x;
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
		// printf("stk:\n");
		do{
			// printf("%d %d\n", stk[top-1], sz);
			flag[stk[top-1]] = sz;
			ins[stk[top-1]] = 0;
			top--;
		} while(stk[top] != x);
		sz++;
	}
}
bool solve(){
	memset(out, 0, sizeof(out));
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < v[i].size();j++){
			int y = v[i][j];
			if(flag[i] != flag[y]){
				out[flag[i]]++;
			}
		}
	// for(int i = 0;i < n;i++)
		// printf("%d -> %d  out %d\n", i+1, flag[i], out[i]);
	int r = 0, p = -2;
	for(int i = 0;i < sz;i++)
		if(out[i] == 0){
			r++;
			p = i;
		}
	if(r == 0) p = 0;
	if(r > 1) return false;
	// printf("%d %d\n", r, p);
	int ss = 0;
	for(int i = 0;i < n;i++) if(flag[i] == p){
		if(ss) printf(" ");
		printf("%d", i+1);
		ss = 1;
	}
}
int main()
{
	while(scanf("%d", &n), n){
		scanf("%d", &m);
		memset(v, 0, sizeof(v));
		for(int i = 0;i < m;i++){
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			v[x].push_back(y);
		}
		memset(vis, 0, sizeof(vis));
		memset(ins, 0, sizeof(ins));
		memset(flag, 0, sizeof(flag));
		top = sz = 0;
		for(int i = 0;i < n;i++) if(!vis[i])
			strong(i);
		if(!solve())
			printf("\n");
	}
	return 0;
}