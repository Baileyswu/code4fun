#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 510
int n, line[N][N], girl[N], used[N];
bool find(int x){
	// printf("find x %d \n", x);
	if(girl[x] != -1) return false;
	// for(int i = 0;i < n;i++) printf("%d%c", girl[i], " \n"[i==n-1]);
	for(int i = 0;i < n;i++) if(line[x][i] && !used[i]){
		// printf("x = %d i = %d\n", x, i);
		used[i] = 1;
		if(girl[i] == -1 || find(girl[i])){
			girl[i] = x;
			// girl[x] = i;
			// printf("girl[%d] = %d \n", i, x);
			return true;
		}
	}
	return false;
}
int main()
{
	while(~scanf("%d", &n)){
		memset(line, 0, sizeof(line));
		memset(used, 0, sizeof(used));
		memset(girl, -1, sizeof(girl));
		for(int i = 0;i < n;i++){
			int num, m;
			scanf("%d: (%d)", &num, &m);
			// printf("%d %d\n", num, m);
			while(m--){
				int t;
				scanf("%d", &t);
				line[num][t] = 1;
			}
		}
		int ans = 0;
		for(int i = 0;i < n;i++){
			if(find(i)) ans++;
			// printf("ans %d\n", ans);
		}
		if(ans % 2) ans++;
		// printf("%d\n", ans);
		printf("%d\n", n-ans/2);
	}
	return 0;
}