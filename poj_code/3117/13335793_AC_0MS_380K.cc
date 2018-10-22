#include <stdio.h>
int main()
{
	int t, n, x, sum;
	char name[12];
	while(scanf("%d%d", &t, &n), t)
	{
		sum = 0;
		while(t--)
		{
			scanf("%s%d", name, &x);
			sum += x;
		}
		printf("%d\n", 3 * n - sum);
	}
}