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
int merge(int x, int y){
	int px = get(x), py = get(y);
	if(px != py){
		p[px] = py;
		a[px] = ((a[y]-a[x]+a[py])%3+3)%3;
		return 0;
	}
	return (a[x]-a[y])%3 ? 1 : 0;
}
int eat(int x, int y){
	int px = get(x), py = get(y);
	if(px != py){
		p[px] = py;
		a[px] = a[py]+1;
		return 0;
	}
	return ((a[x]-a[y])%3+3)%3 == 1 ? 0 : 1;
}
void pr(){
	for(int i = 1;i <= 10;i++)
		printf("%3d ", a[i]);
	printf("\n");
	for(int i = 1;i <= 10;i++)
		printf("%3d ", p[i]);
	printf("\n");
	printf("\n");
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
			if(c == 1) ans += merge(x, y);
			else ans += eat(x, y);
			// printf("c, x, y %d %d %d\n", c, x, y);
			// pr();
			// printf("ans = %d\n", ans);
		}
		printf("%d\n", ans);
	// }
	return 0;
}