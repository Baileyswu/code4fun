

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define N 16010
std::vector<int> v[N];
struct tree
{
	int l, r, num, son;
	tree(){}
	tree(int l, int r, int num, int son): l(l), r(r), num(num), son(son) {}
	void pr(){
		printf("%d %d %d %d\n", l, r, num+1, son);
	}
}T[3*N];
struct node
{
	int y1, y2, x;
	void sc(){
		scanf("%d%d%d", &y1, &y2, &x);
		y1 *= 2; y2 *= 2;
	}
	void pr(){
		printf("%d %d~%d\n", x, y1, y2);
	}
}p[N];
bool cmp(node a, node b){
	if(a.x == b.x) return a.y1 < b.y1;
	return a.x < b.x;
}
void init(int rt, int l, int r){
	T[rt] = tree(l, r, -1, 0);
	if(r == l) return;
	int mid = (r+l)/2;
	init(rt*2, l, mid);
	init(rt*2+1, mid+1, r);
}
void pu(int x, int y){
	// printf("push %d %d\n", x+1, y+1);
	int z = v[x].size();
	if(z < 1 || v[x][z-1] != y)
		v[x].push_back(y);
}
void update(int rt, int l, int r, int ll, int rr, int y){
	if(rr < ll || rr < l || r < ll) return;
	if(ll <= l && r <= rr){
		if(T[rt].son == 0){
			if(T[rt].num != -1)
				pu(T[rt].num, y);
			T[rt].num = y;
			return;
		}
		T[rt].son = 0;
		T[rt].num = y;
		int mid = (l+r)/2;
		update(rt*2, l, mid, ll, rr, y);
		update(rt*2+1, mid+1, r, ll, rr, y);
		return;
	}
	int mid = (l+r)/2;
	if(T[rt].son == 0){
		T[rt*2] = tree(l, mid, T[rt].num, 0);
		T[rt*2+1] = tree(mid+1, r, T[rt].num, 0);
		T[rt].son = 1;
	}
	update(rt*2, l, mid, ll, rr, y);
	update(rt*2+1, mid+1, r, ll, rr, y);
}
int cp(int x, int y, int i){
	int j = 0, r = 0;
	while(i < v[x].size() && j < v[y].size()){
		if(v[x][i] == v[y][j]) {
			r++; i++; j++;
		}
		else if(v[x][i] < v[y][j]) i++;
		else j++;
	}
	// printf("%d %d %d\n", x+1, y+1, r);
	return r;
}
void show(int rt, int l, int r){
	T[rt].pr();
	if(l == r) return;
	int mid = (l+r)/2;
	show(rt*2, l, mid);
	show(rt*2+1, mid+1, r);
}
int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--){
		memset(v, 0, sizeof(v));
		int n, maxy = -1;
		scanf("%d", &n);
		for(int i = 0;i < n;i++){
			p[i].sc();
			maxy = max(maxy, p[i].y2);
		}
		init(1, 0, maxy);
		sort(p, p+n, cmp);
		for(int i = 0;i < n;i++){
			// printf("i = %d \n", i+1);
			// p[i].pr();
			update(1, 0, maxy, p[i].y1, p[i].y2, i);
			// show(1, 0, maxy);
			// printf("\n");
		}
		// for(int i = 0;i < n;i++){
		// 	printf("%d::", i+1);
		// 	for(int j = 0;j < v[i].size();j++)
		// 		printf("%d ", v[i][j]+1);
		// 	printf("\n");
		// }
		int ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < v[i].size();j++)
				ans += cp(i, v[i][j], j);
		printf("%d\n", ans);
	}
	return 0;
}
