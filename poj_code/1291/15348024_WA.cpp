#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1100
int p[N], a[N], s[N], r[N];
int get(int x){
	if(p[x] != x){
		int t = get(p[x]);
		a[x] += a[p[x]]%2;
		p[x] = t;
	}
	return p[x];
}
bool merge(int x, int y, int d){
	if(x == y && d) return false;
	if(p[x] == p[y])
		return ((a[x]-a[y])%2+2)%2 == d;
	a[p[x]] = (((a[x]-a[y])%2+2)%2)^d;
	s[p[y]] += s[p[x]];
	p[p[x]] = p[y];
	return true;
}
int main()
{
	int n;
	while(scanf("%d", &n), n){
		for(int i = 0;i < n;i++){
			p[i] = i;
			a[i] = 0;
			s[i] = 1;
			r[i] = 0;
		}
		int ans = 0;
		for(int i = 0;i < n;i++){
			char s0[10], s1[5], s2[10];
			int num, q;
			scanf("%s%d%s%s", s0, &num, s1, s2);
			if(ans == -1) continue;
			num--;
			get(i); get(num);
			if(!strcmp(s2, "true.")) q = 0;
			else q = 1;
			if(!merge(i, num, q))
				ans = -1;
		}
		if(ans == -1) printf("Inconsistent\n");
		else{
			for(int i = 0;i < n;i++){
				get(i);
				if(a[i]) r[p[i]]++;
			}
			for(int i = 0;i < n;i++){
				if(p[i] == i)
					ans += max(s[i]-r[i], r[i]);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}