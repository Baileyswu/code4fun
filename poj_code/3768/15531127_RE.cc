#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 7
char mp[N][800][800];
int a[N] = {1}, f[N] = {1};
void pt(int x, int y, int d){
	// printf("pt %d %d %d %d\n", x, y, d, a[d]);
	for(int i = 0;i < a[d];i++)
		for(int j = 0;j < a[d];j++)
			mp[d+1][x+i][y+j] = mp[d][i][j];
}
void dfs(int n){
	if(n == 0) return;
	dfs(n-1);
	for(int i = 0;i < a[0];i++)
		for(int j = 0;j < a[0];j++)
			if(mp[0][i][j] != ' ')
				pt(i*a[n-1], j*a[n-1], n-1);
}
void pr(int n){
	for(int i = 0;i < a[n];i++)
		printf("%s\n", mp[n][i]);
}
int main(){
	int n, m;
	while(scanf("%d", &n), n){
		getchar();
		for(int i = 0;i < n;i++)
			gets(mp[0][i]);
		a[0] = strlen(mp[0][0]);
		f[0] = a[0] * a[0];
		scanf("%d", &m);
		for(int i = 1;i < m;i++){
			a[i] = a[i-1] * a[0];
			f[i] = a[i] * a[i];
			// printf("i = %d a = %d f = %d\n", i, a[i], f[i]);
		}
		for(int k = 1;k < m;k++)
			for(int i = 0;i < a[k];i++){
				for(int j = 0;j < a[k];j++)
					mp[k][i][j] = ' ';
			}
		dfs(m-1);
		pr(m-1);
	}
	return 0;
}
