#include <stdio.h>
#define N 4501
long long dp[N][N];
int n, m;
int main()
{
	int i, j;
	for(i = 1;i <= n;i++)
		dp[1][i] = 1;
	scanf("%d%d", &m, &n);
	for(i = 2;i <= m;i++)
		for(j = 1;j <= n;j++)
		{
			dp[j][i] = dp[j][i - 1];
			if(i == j)
				dp[j][i]++;
			else if(j > i)
				dp[j][i] += dp[j - i][i];
			if(dp[j][i] >= 1000000007)
				dp[j][i] -= 1000000007;
		}
	printf("%lld\n", dp[n][m]);
	return 0;
}