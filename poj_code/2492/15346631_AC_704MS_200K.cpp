#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1000010
int n, m, p[N], a[N];
int get(int x){
	if(x != p[x]){
		int t = get(p[x]);
		a[x] += a[p[x]]%2;
		p[x] = t;
	}
	return p[x];
}
int main()
{
	int T, o = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		int u, v;
		for(int i = 0;i < n;i++){
			p[i] = i;
			a[i] = 0;
		}
		int ans = 0;
		for(int i = 0;i < m;i++){
			scanf("%d%d", &u, &v);
			if(ans) continue;
			u--; v--;
			get(u); get(v);
			if(p[u] != p[v]){
				a[p[v]] %= 2;
				a[p[u]] = a[u]%2 == a[v]%2 ? 1:0;
				p[p[u]] = p[v];
			}
			else if(a[u] % 2 == a[v] % 2) ans = 1;
		}
		printf("Scenario #%d:\n", ++o);
		if(ans) printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
}