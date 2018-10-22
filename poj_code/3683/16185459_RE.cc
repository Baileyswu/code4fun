#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1100
int n;
struct node
{
	int l, r;
	node(){}
	node(int l, int r) : l(l), r(r) {
		// pr();
	}
	void pr() {
		// printf("[%d, %d]\n", l, r);
		printf("%02d:%02d %02d:%02d\n", l/60, l%60, r/60, r%60);
	}
}a[N<<1];
int tm() {
	int a, b;
	scanf("%d:%d", &a, &b);
	return a * 60 + b;
}
std::vector<int> G[N<<0];
int vis[N << 1];
int dfn[N<<1], low[N<<1], stk[N<<1], ins[N<<1], clus[N<<1];
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

int dt(int x) {
	return x == 0 ? 0 : (x > 0 ? 1 : -1);
}
bool cross(node a, node b) {
	return dt((a.l - b.l) * (a.l - b.r))
		 * dt((a.r - b.l) * (a.r - b.r)) < 0 
		|| (a.l == b.l && a.r == b.r);
}
void addG(int x, int y) {
	G[x].push_back(y);
	// printf("addG %d %d\n", x, y);
}
bool make() {
	memset(G, 0, sizeof(G));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++) if(i != j) {
			if(cross(a[i<<1], a[j<<1]) && !cross(a[i<<1], a[j<<1|1]))
				addG(i<<1, j<<1|1);
			if(cross(a[i<<1], a[j<<1|1]) && !cross(a[i<<1], a[j<<1]))
				addG(i<<1, j<<1);
			if(cross(a[i<<1|1], a[j<<1]) && !cross(a[i<<1|1], a[j<<1|1]))
				addG(i<<1|1, j<<1|1);
			if(cross(a[i<<1|1], a[j<<1|1]) && !cross(a[i<<1|1], a[j<<1]))
				addG(i<<1|1, j<<1);
		}
	memset(vis, 0, sizeof(vis));
	top = clk = cn = 0;
	for(int i = 0;i < 2*n;i++) 
		if(!vis[i])
			Tarjon(i);
	// for(int i = 0;i < 2*n;i++)
	// 	printf("clus[%d]=%d\n", i, clus[i]);
	for(int i = 0;i < n;i++)
		if(clus[i<<1] == clus[i<<1|1])
			return false;
	return true;
}
std::vector<int> T[N<<1];
int anti[N<<1];
void dfs(int x, int c) {
	vis[x] = c;
	vis[anti[x]] = -c;
	for(int j = 0;j < T[x].size();j++) 
		if(!vis[T[x][j]])
			dfs(T[x][j], c);
}
void addT(int x, int y) {
	T[x].push_back(y);
	// printf("addT %d -> %d\n", x, y);
}
void solve() {
	printf("YES\n");
	memset(T, 0, sizeof(T));
	// printf("cn = %d\n", cn);
	for(int i = 0;i < n;i++) {
		anti[clus[i<<1]] = clus[i<<1|1];
		anti[clus[i<<1|1]] = clus[i<<1];
	}
	for(int i = 0;i < 2*n;i++)
		for(int j = 0;j < G[i].size();j++)
			addT(clus[i], clus[G[i][j]]);
	memset(vis, 0, sizeof(vis));
	for(int i = 0;i < cn;i++) if(!vis[i])
		dfs(i, 1);
	for(int i = 0;i < 2*n;i++) if(vis[clus[i]] == 1)
		a[i].pr();
}
int main()
{
	while(~scanf("%d", &n)) {
		for(int i = 0;i < n;i++) {
			int at = tm(), bt = tm(), c;
			scanf("%d", &c);
			a[i<<1] = node(at, at+c);
			a[i<<1|1] = node(bt-c, bt);
		}
		if(make()) solve();
		else printf("NO\n");
	}
	return 0;
}