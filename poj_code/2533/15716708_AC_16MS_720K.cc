#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int a[1100], dp[1100];
int main()
{
	int n;
	while(~scanf("%d", &n)){
		a[0] = -1;
		for(int i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		memset(dp, 0, sizeof(dp));
		for(int i = 0;i <= n;i++)
			for(int j = n-1;j >= 0;j--)
				if(a[j] < a[i])
					dp[i] = max(dp[i], dp[j]+1);
		int ans = 0;
		for(int i = 0;i <= n;i++)
			ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}