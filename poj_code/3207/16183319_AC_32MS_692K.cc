/*--------------------------------------------
 * File Name: POJ 3207
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2016-10-12 16:13:50
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 510
int n, m;
struct edge
{
	int u, v;
	void sc() {
		scanf("%d%d", &u, &v);
	}
}ed[N];
int p[N << 1];
int get(int x) {
	if(x != p[x]) p[x] = get(p[x]);
	return p[x];
}
void un(int x, int y) {
	get(x); get(y);
	if(p[x] != p[y]) p[p[x]] = p[y];
}
int dt(int x) {
	return x == 0 ? 0 : (x > 0 ? 1 : -1);
}
bool cross(edge a, edge b) {
	return dt((a.u - b.u) * (a.v - b.u))
		 * dt((a.u - b.v) * (a.v - b.v)) < 0;
}
void make() {
	for(int i = 0;i < 2*m;i++)
		p[i] = i;
	for(int i = 0;i < m;i++)
		for(int j = 0;j < i;j++) {
			if(cross(ed[i], ed[j])) {
				un(i<<1, (j<<1|1));
				un(j<<1, (i<<1|1));
			}
		}
}
bool solve() {
	for(int i = 0;i < m;i++)
		if(p[i<<1] == p[i<<1|1]) 
			return false;
	return true;
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 0;i < m;i++)
			ed[i].sc();
		make();
		if(solve()) printf("panda is telling the truth...\n");
		else printf("the evil panda is lying again\n");
	}
	return 0;
}