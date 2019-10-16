#include <bits/stdc++.h>
using namespace std;
#define N 110
int dp[N][N];
int main() {
	int n = 10;
	int len = 2 * n;

	memset(dp, 0, sizeof(dp));
	for(int i = 0;i <= len;i++) {
		dp[i][0] = 1;
	}
	for(int i = 0;i <= len;i++)
		for(int j = 1;j <= i;j++) {
			dp[i][j] = dp[i-1][j];
			if (2 * j <= i)
				dp[i][j] += dp[i-1][j-1];
		}
	for(int i = 0;i <= len;i++)
		for(int j = 0;j <= i;j++)
			printf("%d%c", dp[i][j], " \n"[i == j]);
}