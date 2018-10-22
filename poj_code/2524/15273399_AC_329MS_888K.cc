#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 50010
int p[N];
int get(int x){
	if(p[x] != x) p[x] = get(p[x]);
	return p[x];
}
void merge(int x, int y){
	p[get(x)] = get(y);
}
int main()
{
	int n, m, o = 0;
	while(scanf("%d%d", &n, &m)){
		if(!n && !m) break;
		for(int i = 1;i <= n;i++)
			p[i] = i;
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			merge(x, y);
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			get(i);
			if(p[i] == i)
				ans++;
		}
		printf("Case %d: %d\n", ++o, ans);
	}
	return 0;
}