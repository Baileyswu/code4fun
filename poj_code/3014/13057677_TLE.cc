#include <stdio.h>
#define N 4501
long long dp[N][N];
int main()
{
	int n, m;
	int i, j;
	for(j = 0;j < N;j++)
		dp[j][1] = 1;
	for(i = 0;i < N;i++)
		dp[1][i] = 1;
	scanf("%d%d", &m, &n);
	for(i = 2;i <= m;i++)
		for(j = 2;j <= n;j++)
		{
			dp[j][i] = dp[j][i - 1];
			if(j > i)
				dp[j][i] += dp[j - i][i];
			else if(i == j)
				dp[j][i]++;
			while(dp[j][i] >= 1000000007)
				dp[j][i] -= 1000000007;
		}
	printf("%lld\n", dp[n][m]);
	return 0;
}