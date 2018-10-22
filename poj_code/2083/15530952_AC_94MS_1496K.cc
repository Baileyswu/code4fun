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
	// printf("n == %d\n", n);
	pt(0, 0, n-1);
	pt(0, 2*a[n-1], n-1);
	pt(a[n-1], a[n-1], n-1);
	pt(2*a[n-1], 0, n-1);
	pt(2*a[n-1], 2*a[n-1], n-1);
}
void pr(int n){
	for(int i = 0;i < a[n];i++)
		printf("%s", mp[n][i]);
	printf("-\n");
}
int main(){
	for(int i = 1;i < N;i++)
		a[i] = a[i-1] * 3;
	for(int i = 0;i < N;i++)
		f[i] = a[i] * a[i];
	for(int m = 0;m < N;m++)
		for(int i = 0;i < a[m];i++){
			for(int j = 0;j < a[m];j++)
				mp[m][i][j] = ' ';
			mp[m][i][a[m]] = '\n';
		}
	mp[0][0][0] = 'X';
	dfs(N-1);
	int n;
	while(~scanf("%d", &n)){
		if(n == -1) break;
		n--;
		pr(n);
	}
	return 0;
}
