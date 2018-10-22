#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 10010
struct node{
	int a, d;
	void sc(){
		scanf("%d%d", &a, &d);
	}
	void pr(){
		printf("%d %d\n", a, d);
	}	
}p[N];
int b[N], f[N], n, day;
bool cmp(node x, node y){
 	return x.a == y.a ? x.d < y.d : x.a > y.a;
}
int get(int x){
	return f[x] == x ? f[x] : f[x]=get(f[x]);
}
void pp(){
	for(int i = 1;i <= day;i++)
		printf("%3d%c", f[i], " \n"[i==day]);
	for(int i = 1;i <= day;i++)
		printf("%3d%c", b[i], " \n"[i==day]);
}
int main(){
	while(~scanf("%d", &n)){
		day = 0;
		for(int i = 0;i < n;i++){
			p[i].sc();
			day = max(day, p[i].d);
		}
		sort(p, p+n, cmp);
		memset(b, 0, sizeof(b));
		for(int i = 0;i <= day;i++)
			f[i] = i;
		int x, l;
		for(int i = 0;i < n;i++){
		    int x = p[i].d;
		    int l = get(x);
		    if(l < 1) continue;
		    b[l] = p[i].a;
		    f[l] = get(l-1);
		}
		int ans = 0;
		for(int i = 1;i <= day;i++)
			ans += b[i];
		cout << ans << endl;
	}
	return 0;
}