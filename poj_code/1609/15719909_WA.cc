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
}p[N];
bool cmp1(node x, node y){
	if(x.b == y.b) x.a < y.a;
	return x.b < y.b;
}
bool cmp2(node x, node y){
	if(x.a == y.a) x.b < y.b;
	return x.a < y.a;
}
int find(int x){
	int l = 1, r = top-1, cnt = 32;
	while(l < r && cnt--){
		int mid = l+r >> 1;
		if(stk[mid] == x) return mid;
		if(stk[mid] < x) l = mid;
		else r = mid;
	}
	if(stk[l] < x) return r;
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
			if(p[i].a >= stk[top-1])
				stk[top++] = p[i].a;
			else {
				int s = find(p[i].a);
				stk[s] = p[i].a;
			}
		}
		int ans = top-1;
		// printf("%d  d\n", ans);
		sort(p, p+n, cmp2);
		top = 0;
		stk[top++] = -1;
		for(int i = 0;i < n;i++) {
			if(p[i].b >= stk[top-1])
				stk[top++] = p[i].b;
			else {
				int s = find(p[i].b);
				stk[s] = p[i].b;
			}
		}
		ans = max(ans, top-1);
		printf("%d\n", ans);
	}
	printf("*\n");
	return 0;
}