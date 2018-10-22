#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
LL ans[1100];
int main() {
	int n, k;
	while(~scanf("%d%d", &n, &k)) {
		for(int j = 0;j <= n;j++)
			ans[j] = 1;
		for(int i = 2;i <= k;i++) {
			for(int j = i;j <= n;j++)
				ans[j] += ans[j-i];
		}
		//for(int j = 0;j <= n;j++)
		//	printf("%2lld%c", ans[j], " \n"[j==n]);
		printf("%lld\n", ans[n]);
	}
}