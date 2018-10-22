#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 10010
using namespace std;
struct node{
	int a, d;
	void sc(){ scanf("%d%d", &a, &d); }
}p[N];
int buy[N], n;
bool cmp(node x, node y){
	if(x.d == y.d) return x.a > y.a;
	return x.d > y.d;
}
int main(){
	while(~scanf("%d", &n)){
		for(int i = 0;i < n;i++)
			p[i].sc();
		sort(p, p+n, cmp);
		memset(buy, 0, sizeof(buy));
		int ans = 0, day = p[0].d, i;
		buy[day--] = p[0].a;
		for(i = 1;i < n;i++){
			if(p[i].d >= day)
				buy[day] = max(buy[day], p[i].a);
			else{
				day = p[i].d;
				buy[day] = p[i].a;
			}
		}
		for(i = 1;i <= p[0].d;i++)
			ans += buy[i];
		printf("%d\n", ans);
	}
	return 0;
}