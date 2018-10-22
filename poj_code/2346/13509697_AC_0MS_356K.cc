#include <stdio.h>
#include <math.h>
int main()
{
	int n, f[6][50] = {0}, k, k1, i, j;
	for(j = 0;j < 10;j++)
		f[1][j] = 1;
	for(j = 10;j < 46;j++)
		f[1][j] = 0;
	for(i = 1;i < 5;i++)
		for(k = 0;k <= 9 * (i + 1);k++)
		{
			f[i + 1][k] = 0;
			for(k1 = 0;k1 <= k;k1++)
				f[i + 1][k] += f[i][k1] * f[1][k - k1];
		}
	while(~scanf("%d", &n))
	{
		n /= 2;
		int ans = 0;
		for(j = 0;j <= 9 * n;j++)
			ans += f[n][j] * f[n][j];
		printf("%d\n", ans);
	}
	return 0;
}