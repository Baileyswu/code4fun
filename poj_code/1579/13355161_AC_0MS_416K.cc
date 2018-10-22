#include <stdio.h>
int a[21][21][21];
int main()
{
	int i, j, k;
	a[0][0][0] = 1;
	for(i = 0;i < 21;i++)
		for(j = 0;j < 21;j++)
			for(k = 0;k < 21;k++)
			{
				if(!i || !j || !k)
					a[i][j][k] = 1;
				else if(i < j && j < k)
					a[i][j][k] = a[i][j][k-1] + a[i][j-1][k-1] - a[i][j-1][k];
				else
					a[i][j][k] = a[i-1][j][k] + a[i-1][j-1][k] + a[i-1][j][k-1] - a[i-1][j-1][k-1];
			}
	while(scanf("%d%d%d", &i, &j, &k) && (i + 1 || j + 1 || k + 1))
	{
		printf("w(%d, %d, %d) = ", i, j, k);
		if(i <= 0 || j <= 0 || k <= 0)
			printf("1\n");
		else if(i > 20 || j > 20 || k > 20)
			printf("%d\n", a[20][20][20]);
		else
			printf("%d\n", a[i][j][k]);
	}
	return 0;
}