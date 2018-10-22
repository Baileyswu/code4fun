#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 200
int n;
struct node
{
	double x, y;
	int num;
	void sc(int i){
		scanf("%lf%lf", &x, &y);
		num = i;
	}
	double dis(node q){
		return sqrt(pow(x-q.x,2)+pow(y-q.y,2));
	}
}p[N];
int f[N];
struct edge
{
	int u, v;
	double ds;
	edge(){}
	edge(int u, int v, double ds): u(u), v(v), ds(ds){}
	void pr(){
		printf("%d %d %.2f\n", u, v, ds);
	}
}s[N*N];
bool cmp(edge x, edge y){
	return x.ds < y.ds;
}
int get(int x){
	if(f[x] != x){
		f[x] = get(f[x]);
	}
	return f[x];
}
int main()
{
	while(~scanf("%d", &n)){
		for(int i = 0;i < n;i++){
			p[i].sc(i);
		}
		int cnt = 0;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < i;j++) {
				s[cnt++] = edge(i, j, p[i].dis(p[j]));
			}
		for(int i = 0;i < n;i++)
			f[i] = i;
		sort(s, s+cnt, cmp);
		double ans = 0;
		for(int i = 0;i < cnt;i++){
			// s[i].pr();
			int u = s[i].u, v = s[i].v;
			// f[u] = get(u); f[v] = get(v);
			if(get(u) == get(v)) continue;
			ans += s[i].ds;
			f[f[v]] = f[u];
			// for(int j = 0;j < n;j++)
				// printf("%d%c", f[j], " \n"[j==n-1]);
		}
		printf("%.2f\n", ans);
	}
	return 0;
}