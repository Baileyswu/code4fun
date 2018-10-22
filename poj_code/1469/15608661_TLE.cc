#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 510

int a[N][N], res[N], use[N], n, m;
void pr(){
	for(int i = 1;i <= n;i++)
		printf("%2d%c", use[i], " \n"[i==n]);
	for(int i = 1;i <= n;i++)
		printf("%2d%c", res[i], " \n"[i==n]);
	printf("\n");
}
bool find(int x){
	// printf("find %d\n", x);
	// pr();
	for(int i = 1;i <= n;i++){
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
	for(int i = 1;i <= n;i++){
		memset(use, 0, sizeof(use));
		if(find(i))
			ans++;
	}
	printf("%d\n", ans);
}
int main()
{
	while(~scanf("%d%d", &n, &m)){
		memset(a, 0, sizeof(a));
		memset(res, 0, sizeof(res));
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
		}
		// for(int i = 1;i <= n;i++)
		// 	for(int j = 1;j <= n;j++)
		// 		printf("%d%c", a[i][j], " \n"[j==n]);
		solve();
	}
	return 0;
}