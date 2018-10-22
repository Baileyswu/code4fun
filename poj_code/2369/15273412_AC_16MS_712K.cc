#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1010
#define LL long long
int a[N],flag[N], b[N], p, n, num[N], pri[N], prin = 0, po[N];
int gao(int x){
	int r = 1, y = x;
	while(a[x] != y){
		flag[x] = 1;
		x = a[x];
		r++;
	}
	flag[x] = 1;
	//for(int i = 1;i <= n;i++)
	//	printf("%d ", flag[i]);
	//printf("\n");
	return r;
}
void set(){
	memset(num, 0, sizeof(num));
	for(int i = 2;i < N;i++)
		for(int j = i*i; j < N;j += i) if(!num[j])
			num[j] = 1;
	for(int i = 2;i < N;i++) if(!num[i])
		pri[prin++] = i;
}
void solve(int x){
	//printf("x = %d\n", x);
	for(int i = 0;i < prin && x >= pri[i];i++){
		int t = 0;
		while(x % pri[i] == 0){
			t++;
			x /= pri[i];
		}
		po[i] = max(po[i], t);
		//printf("t %d %d\n", pri[i], po[i]);
	}
	//for(int i = 0;i < prin;i++) if(po[i])
		//printf("this %d %d\n", pri[i], po[i]);
}
int main()
{
	set();
	while(~scanf("%d", &n)){
		for(int i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		memset(flag, 0, sizeof(flag));
		memset(po, 0, sizeof(po));
		p = 0;
		for(int i = 1;i <= n;i++)
			if(!flag[i])
				b[p++] = gao(i);
		for(int i = 0;i < p;i++)
			solve(b[i]);
		LL ans = 1;
		for(int i = 0;i < prin;i++) if(po[i]){
			//printf("%d %d\n", pri[i], po[i]);
			for(int j = 0;j < po[i];j++)
				ans *= 1LL*pri[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}