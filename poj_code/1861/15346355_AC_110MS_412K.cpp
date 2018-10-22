#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1100
#define M 15010
int n, m, f[N];
struct edge
{
	int u, v, ds, yes;
	void sc(){
		scanf("%d%d%d", &u, &v, &ds);
		yes = 0;
	}
	void pr(){
		printf("%d %d\n", u, v);
	}
}s[M];
bool cmp(edge x, edge y){
	return x.ds < y.ds;
}
int get(int x){
	return f[x] == x ? f[x] : f[x] = get(f[x]);
}
int main()
{
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0;i < m;i++)
			s[i].sc();
		sort(s, s+m, cmp);
		for(int i = 0;i < n;i++)
			f[i] = i;
		int ans = 0, cnt = 0;
		for(int i = 0;i < m;i++){
			int u = s[i].u, v = s[i].v;
			if(get(u) == get(v)) continue;
			f[f[u]] = f[v];
			ans = max(ans, s[i].ds);
			cnt++;
			s[i].yes = 1;
		}
		printf("%d\n%d\n", ans, cnt);
		for(int i = 0;i < m;i++) if(s[i].yes)
			s[i].pr();
	}
	return 0;
}