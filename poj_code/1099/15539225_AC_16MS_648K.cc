#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 20
int n, a[N][N], L, R;
char str[100][100];
char key[3] = "-|";
void pt(int x, int y, int dx, int dy){
	str[x][y] = 'O';
	str[x-dx][y-dy] = str[x+dx][y+dy] = key[dx];
	str[x-2*dx][y-2*dy] = str[x+2*dx][y+2*dy] = 'H';
}
void prin(){
	for(int i = 0;i < L;i++){
		for(int j = 0;j < R;j++)
			putchar(str[i][j]);
		printf("\n");
	}
}
void wt(int x, int y, int dx, int dy){
	str[x][y] = 'O';
	str[x+dx][y+dy] = key[abs(dx)];
	str[x+2*dx][y+2*dy] = 'H';
}
int main()
{
	int o = 0;
	while(~scanf("%d", &n)){
		if(n == 0) break;
		if(o) printf("\n");
		printf("Case %d:\n\n", ++o);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				scanf("%d", &a[i][j]);
		L = 4*n-1, R = 4*n+3;
		for(int i = 0;i < L;i++)
			for(int j = 0;j < R;j++)
				str[i][j] = ' ';
		for(int j = 0;j < R;j++)
			str[0][j] = str[L-1][j] = '*';
		for(int i = 0;i < L;i++)
			str[i][0] = str[i][R-1] = '*';
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++){
				if(a[i][j] == 1) pt(4*i+1, 4*j+3, 0, 1);
				else if(a[i][j] == -1) pt(4*i+1, 4*j+3, 1, 0);
			}
		int sum = 0;
		for(int i = 0;i < n;i++){
			sum = 0;
			for(int j = 0;j < n;j++){
				sum += a[i][j];
				if(a[i][j]) continue;
				else if(sum) wt(4*i+1, 4*j+3, 0, 1);
				else wt(4*i+1, 4*j+3, 0, -1);
			}
		}
		for(int j = 0;j < n;j++){
			sum = 0;
			for(int i = 0;i < n;i++){
				sum += a[i][j];
				if(a[i][j]) continue;
				else if(sum) wt(4*i+1, 4*j+3, -1, 0);
				else wt(4*i+1, 4*j+3, 1, 0);
			}
		}
		prin();
	}
	return 0;
}