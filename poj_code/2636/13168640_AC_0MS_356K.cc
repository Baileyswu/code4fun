#include <stdio.h>
#include <math.h>
int main()
{
	int t, sum, n, x;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		sum = 1 - n;
		while(n--)
		{
			scanf("%d", &x);
			sum += x;
		}
		printf("%d\n", sum);
	}
	return 0;
}