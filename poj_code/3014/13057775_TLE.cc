#include <stdio.h>
#define N 4502
int dp[N][N];
int set()
{
	int i, j;
	for(j = 0;j < N;j++)
		dp[j][1] = 1;
	for(i = 0;i < N;i++)
		dp[1][i] = 1;
	for(i = 2;i < N;i++)
		for(j = 2;j < N;j++)
		{
			if(j > i)
				dp[j][i] = dp[j - i][i] + dp[j][i - 1];
			else if(i == j)
				dp[j][i] = 1 + dp[j][i - 1];
			else
				dp[j][i] = dp[j][j];
			if(dp[j][i] >= 1000000007)
				dp[j][i] -= 1000000007;
		}
	return 0;
}
int main()
{
	int i, j;
	set();
	while(~scanf("%d%d", &i, &j))
		printf("%d\n", dp[j][i]);
	return 0;
}