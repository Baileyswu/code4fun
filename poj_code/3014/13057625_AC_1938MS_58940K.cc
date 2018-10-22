#include <stdio.h>
#define size 4501
int n, m, dp[size][size];
int main()
{
    scanf("%d%d", &n ,&m);
    for(int i = 1; i <= m; i++)
		dp[1][i] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (i == j) dp[i][j]++;
            if (j > i) dp[i][j] += dp[i][j - i];
            if (dp[i][j] >= 1000000007) dp[i][j] -= 1000000007;
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}