#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 510
int o = 0;
int a[N][N], res[N], use[N], n, m;
#define RIGHT m
#define LEFT n
bool find(int x){
	for(int i = 1;i <= RIGHT;i++){
		if(a[x][i] && !use[i]){
			use[i] = 1;
			if(res[i] == 0 || find(res[i])){
				res[i] = x;
				return true;
			}
		}
	}
	return false;
}

void solve(){
	int ans = 0;
	for(int i = 1;i <= LEFT;i++){
		memset(use, 0, sizeof(use));
		if(find(i))
			ans++;
	}
	// printf("%d\n", ans);
	printf("Case %d: %d\n", ++o, n+m-ans);
}
int main()
{
	int t;
	while(~scanf("%d%d%d", &n, &m, &t)){
		if(!n && !m && !t) break;
		memset(a, 1, sizeof(a));
		memset(res, 0, sizeof(res));
		while(t--){
			int x, y;
			scanf("%d%d", &x, &y);
			a[x][y] = 0;
		}
		// for(int i = 1;i <= n;i++)
			// for(int j = 1;j <= m;j++)
				// printf("%d%c", a[i][j], " \n"[j==m]);
		solve();
	}
	return 0;
}