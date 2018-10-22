#include <bits/stdc++.h>
using namespace std;
#define N 250
int mp[N][N], ans, lt[N], n, m, vis[N];
queue <int> Q;
void pr() {
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			printf("%2d%c", mp[i][j], " \n"[j==n]);
}
bool bfs(int s, int t) {
//	printf("bfs %d -> %d\n", s, t);
	while(!Q.empty()) Q.pop();
	Q.push(s);
	memset(lt, 0, sizeof(lt));
	memset(vis, 0, sizeof(vis));
	lt[s] = s;
	vis[s] = 1;
	int i;
	while(!Q.empty()) {
		s = Q.front(); Q.pop();
//		printf("s in Q = %d\n", s);
		for(i = 1;i <= n;i++)
			if(!vis[i] && mp[s][i]) {
				vis[i] = 1;
				Q.push(i);
				lt[i] = s;
				if(i == t)
					break;
			}
		if(i == t) break;
	}
	if(i != t) return false;
	s = t;
	int k = mp[lt[s]][s];
	while(lt[s] != s) {
		k = min(k, mp[lt[s]][s]);
		s = lt[s];
	}
	s = t;
	while(lt[s] != s) {
		mp[lt[s]][s] -= k;
		mp[s][lt[s]] += k;
		s = lt[s];
	}
	ans += k;
	//printf("+%d -> %d\n", k, ans);
//	pr();
	return true;
}
int main() {
	while(~scanf("%d%d", &m, &n)) {
	//	printf("n=%d m= %d\n", n, m);
		memset(mp, 0, sizeof(mp));
		for(int i = 0;i < m;i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			mp[u][v] += w;
		}
	//	pr();
		ans = 0;
		while(bfs(1, n));
		printf("%d\n", ans);
	}
	return 0;
}
