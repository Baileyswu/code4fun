#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 110
int n, m, p[N], a[N], f[N], T[N][N], l[2][N], ln[2], r[2][N], rn[2];
int get(int x){
	if(x != p[x]){
		int t = get(p[x]);
		a[x] += a[p[x]];
		p[x] = t;
	}
	a[x] %= 2;
	return p[x];
}
void pf(){
	for(int i = 0;i < n;i++)
		printf("%d%c", p[i], " \n"[i==n-1]);
	for(int i = 0;i < n;i++)
		printf("%d%c", a[i], " \n"[i==n-1]);
	printf("\n");
}
bool merge(int x, int y){
	// printf("%d %d\n", x, y);
	get(x); get(y);
	if(p[x] == p[y]) return a[x]%2 != a[y]%2;
	a[p[x]] = 1-(((a[x]-a[y])%2+2)%2);
	p[p[x]] = p[y];
	return true;
}
void out(){
	memset(T, 0, sizeof(T));
	for(int i = 0;i < n;i++){
		get(i);
		if(p[i] == i) T[i][0] = 1;
	}
	// pf();
	for(int i = 0;i < n;i++)
		T[p[i]][T[p[i]][0]++] = i;
	ln[0] = ln[1] = 0;
	for(int i = 0;i < n;i++) if(T[i][0]){
		// printf("T %d %d\n", i, T[i][0]);
		rn[0] = rn[1] = 0;
		for(int j = 1;j < T[i][0];j++){
			int an = T[i][j];
			r[a[an]-a[i]][rn[a[an]-a[i]]++] = an;
		}
		int u = ln[0] < ln[1] ? 0 : 1, v = rn[0] > rn[1] ? 0 : 1;
		for(int j = 0;j < rn[v];j++)
			l[u][ln[u]++] = r[v][j];
		for(int j = 0;j < rn[1-v];j++)
			l[1-u][ln[1-u]++] = r[1-v][j];
	}
	for(int i = 0;i < 2;i++){
		printf("%d", ln[i]);
		for(int j = 0;j < ln[i];j++)
			printf(" %d", l[i][j]+1);
		printf("\n");
	}
}

int main()
{
	while(~scanf("%d", &n)){
		for(int i = 0;i < n;i++){
			p[i] = i;
			a[i] = 0;
		}
		int flag = 0;
		for(int i = 0;i < n;i++){
			memset(f, 0, sizeof(f));
			while(scanf("%d", &m), m)
				f[m-1] = 1;
			for(int j = 0;j < n;j++) if(i != j && !f[j]){
				if(!merge(i, j)){
					flag = 1;
					break;
				}
				// pf();
			}
		}
		if(flag) printf("No solution\n");
		else out();
	}
	return 0;
}