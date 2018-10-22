#include <bits/stdc++.h>
using namespace std;
int dp[1100][1100];
int main() {
	int n, k;
	while(~scanf("%d%d", &n, &k)) {
		memset(dp, 0, sizeof(dp));
		for(int j = 0;j <= n;j++)
			dp[1][j] = 1;
		for(int i = 2;i <= k;i++) {
			for(int j = 0;j < i;j++)
				dp[i][j] = dp[i-1][j];
			for(int j = i;j <= n;j++)
				dp[i][j] = dp[i-1][j] + dp[i][j-i];
		}
		/*for(int i = 0;i <= k;i++)
			for(int j = 0;j <= n;j++)
				printf("%2d%c", dp[i][j], " \n"[j == n]);*/
		printf("%d\n", dp[k][n]);
	}
}