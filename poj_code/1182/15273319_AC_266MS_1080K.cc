#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 50010
int p[N], a[N], n;
int get(int x){
	if(p[x] != x){
		int t = get(p[x]);
		a[x] += a[p[x]];
		a[x] %= 3;
		p[x] = t;
	}
	return p[x];
}
int merge(int x, int y, int z){
	int px = get(x), py = get(y);
	if(px != py){
		p[px] = py;
		a[px] = ((a[y]-a[x]+a[py]+z)%3+3)%3;
		return 0;
	}
	return ((a[x]-a[y])%3+3)%3 == z ? 0 : 1;
}
int main(){
	int m;
	// while(~scanf("%d%d", &n, &m)){
		scanf("%d%d", &n, &m);
		int ans = 0;
		for(int i = 1;i <= n;i++){
			p[i] = i;
			a[i] = 0;
		}
		while(m--){
			int c, x, y;
			scanf("%d%d%d", &c, &x, &y);
			if(x > n || y > n || (c==2&&x==y)){
				ans++;
				continue;
			}
			ans += merge(x, y, c-1);
		}
		printf("%d\n", ans);
	// }
	return 0;
}