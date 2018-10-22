#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 310
int a[N][N], res[N], use[N], n, m;
void pr(){
	for(int i = 1;i <= m;i++)
		printf("%2d%c", use[i], " \n"[i==m]);
	for(int i = 1;i <= m;i++)
		printf("%2d%c", res[i], " \n"[i==m]);
	printf("\n");
}
bool find(int x){
	// printf("find x = %d\n", x);
	// pr();
	for(int i = 1;i <= m;i++){
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

bool solve(){
	// for(int i = 0;i < n;i++)
	// 	for(int j = 0;j < m;j++)
	// 		printf("%d%c", a[i][j], " \n"[j==m-1]);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		memset(use, 0, sizeof(use));
		if(find(i))
			ans++;
	}
	return ans == n;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int k, d;
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof(a));
		memset(res, 0, sizeof(res));
		for(int i = 1;i <= n;i++){
			scanf("%d", &k);
			while(k--){
				scanf("%d", &d);
				a[i][d] = 1;
			}
		}

		if(solve()) printf("YES\n");
		else printf("NO\n");
		// pr();
	}
	return 0;
}