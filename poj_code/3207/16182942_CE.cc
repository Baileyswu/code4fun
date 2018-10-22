#include <bits/stdc++.h>
using namespace std;
#define N 510
int n, m;
struct edge
{
	int u, v;
	void sc() {
		scanf("%d%d", &u, &v);
	}
}p[N];
std::vector<int> G[N<<1];
int a[N<<1], out[N<<1];
void add(int x, int y) {
	G[x].push_back(y);
	out[x]++;
}
bool cross(edge a, edge b) {
	return (a.u - b.u) * (a.v - b.u) 
		 * (a.u - b.v) * (a.v - b.v) < 0;
}
void make() {
	memset(a, 0, sizeof(a));
	memset(G, 0, sizeof(G));
	memset(out, 0, sizeof(out));
	for(int i = 0;i < m;i++)
		for(int j = 0;j < i;j++) {
			if(cross(p[i], p[j])) {
				add(i<<1, j<<1|1);
				add(j<<1, i<<1|1);
			} else {
				add(i<<1, j<<1);
				add(j<<1|1, i<<1|1);
			}
		}
}
int vis[N<<1], dfn[N<<1], low[N<<1], stk[N<<1], ins[N<<1], clus[N<<1];
int top, clk, cn;
void Tarjon(int x) {
	dfn[x] = low[x] = clk++;
	stk[top++] = x;
	vis[x] = ins[x] = 1;
	for(int j = 0;j < G[x].size();j++) {
		int y = G[x][j];
		if(!vis[y]) {
			Tarjon(y);
			low[x] = min(low[x], low[y]);
		} else if(ins[y]) {
			low[x] = min(low[x], dfn[y]);
		}
	}
	if(low[x] == dfn[x]) {
		do {
			ins[stk[top-1]] = 0;
			clus[stk[top-1]] = cn;
			top--;
		} while(stk[top] != x);
		cn++;
	}
}

std::vector<int> T[N<<1];
void remake() {
	memset(T, 0, sizeof(T));
	memset(out, 0, sizeof(out));
	for(int i = 0;i < (m<<1);i++)
		for(int j = 0;j < G[i].size();j++)
			add(clus[i], clus[G[i][j]]);
}
bool solve() {
	for(int i = 0;i < m;i++)
		if(clus[i<<1] == clus[i<<1|1]) 
			return false;
	return true;
	remake();
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 0;i < m;i++)
			p[i].sc();
		make();
		memset(vis, 0, sizeof(vis));
		cn = top = clk = 0;
		for(int i = 0;i < (m<<1);i++)
			if(!vis[i]) Tarjon(i);
		if(solve()) printf("panda is telling the truth...\n");
		else printf("the evil panda is lying again\n");
	}
	return 0;
}