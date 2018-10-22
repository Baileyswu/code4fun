#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
#define N 110
int dt(int x){
	return x == 0 ? 0 : (x > 0 ? 1 : -1);
}
struct pt
{
	int x, y;
	void sc(){
		scanf("%d%d", &x, &y);
	}
	void pr(){
		printf("%d %d\n", x, y);
	}
};
bool cmp(pt a, pt b){
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
struct seg
{
	pt a, b;
	int v;
	void sc(){
		a.sc(); b.sc();
		v = a.x == b.x? 1 : 0;
		// a.pr(); b.pr();
	}
	bool jo(seg si){
		return (si.a.y <= a.y && si.b.y >= a.y)
			 || (si.a.y >= a.y && si.b.y <= a.y);
	}
}s[N];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int ans = 0;
		for(int i = 0;i < n;i++)
			s[i].sc();
		for(int i = 0;i < n;i++) if(!s[i].v)
			for(int j = 0;j < n;j++) if(!s[j].v && s[j].a.y > s[i].a.y)
				for(int k = 0;k < n;k++) if(s[k].v && s[i].jo(s[k]) && s[j].jo(s[k]))
					for(int l = 0;l < n;l++) if(s[l].v && s[l].a.x > s[k].a.x){
						if(s[i].jo(s[l]) && s[j].jo(s[l]))
							ans++;
					}
		printf("%d\n", ans);
	}
	return 0;
}