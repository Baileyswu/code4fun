#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 10010
int stk[N], top;
struct node
{
	int a, b;
	void pr(){
		printf("(%d %d)\n", a, b);
	}
}p[N];
bool cmp1(node x, node y){
	if(x.b == y.b) x.a < y.a;
	return x.b < y.b;
}
int find(int x){
	int l = 1, r = top-1, cnt = 32;
	while(l < r && cnt--){
		int mid = l+r >> 1;
		if(stk[mid] <= x)	l = mid+1;
		else r = mid;
	}
	if(stk[l] <= x) return r;
	return l;
}
int main()
{
	int n;
	while(scanf("%d", &n), n) {
		for(int i = 0;i < n;i++)
			scanf("%d%d", &p[i].a, &p[i].b);
		sort(p, p+n, cmp1);
		top = 0;
		stk[top++] = -1;
		for(int i = 0;i < n;i++) {
			// p[i].pr();
			if(p[i].a >= stk[top-1])
				stk[top++] = p[i].a;
			else {
				int s = find(p[i].a);
				stk[s] = p[i].a;
			}

			// for(int j = 0;j < top;j++)
			// 	printf("%d%c", stk[j], " \n"[j==top-1]);
		}
		int ans = top-1;
		printf("%d\n", ans);
	}
	printf("*\n");
	return 0;
}