#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 800
#define LL long long
struct pt
{
	double x, y;
	void sc(){
		scanf("%lf%lf", &x, &y);
	}
	double dis(pt &b){
		return sqrt(pow(x-b.x,2)+pow(y-b.y,2));
	}
}a[N];
struct node
{
	int u, v;
	double w;	
	node(){}
	node(int u, int v, double w): u(u), v(v), w(w){}
}p[N*N];
int pa[N];
bool cmp(node x, node y){
	return x.w < y.w;
}
int get(int x){
	if(pa[x] != x) pa[x] = get(pa[x]);
	return pa[x];
}
int main(){
	int n, m;
	scanf("%d", &n);
		for(int i = 0;i < n;i++){
			a[i].sc();
			pa[i] = i;
		}
		scanf("%d", &m);
		while(m--){
			int u, v;
			scanf("%d%d", &u, &v);
			u--;v--;
			get(u); get(v);
			pa[pa[u]] = pa[v];
		}
		int cnt = 0;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < i;j++) if(get(i) != get(j)){
				p[cnt++] = node(i, j, a[i].dis(a[j]));
			}
		sort(p, p+cnt, cmp);
		
		for(int i = 0;i < cnt;i++){
			int u = p[i].u, v = p[i].v;
			get(u); get(v);
			if(pa[u] == pa[v]) continue;
			pa[pa[u]] = pa[v];
			printf("%d %d\n", u+1, v+1);
		}
	

}