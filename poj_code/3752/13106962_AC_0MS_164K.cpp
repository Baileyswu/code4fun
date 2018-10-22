#include <stdio.h>
#define N 100
int a[N][N];
int bend(int n, int m, int i, int j, int x)
{
	if(n == 0 || m == 0)
		return 0;
	for(int k = j;k < j + m;k++)
		a[i][k] = x++;
	if(n == 1)
		return 0;
	x += n - 2;
	for(int k = j + m - 1;k >= j;k--)
		a[i + n - 1][k] = x++;
	if(n == 2)
		return 0;
	x = x - m - n + 2;
	for(int s = i + 1;s < i + n - 1;s++)
		a[s][j + m - 1] = x++;
	if(m == 1)
		return 0;
	x += m;
	for(int s = i + n - 2;s > i;s--)
		a[s][j] = x++;
	bend(n - 2, m - 2, i + 1, j + 1, x);
	return 0;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	bend(n, m, 0, 0, 0);
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
			printf("   %c", a[i][j]%26 + 'A');
		printf("\n");
	}
	return 0;
}