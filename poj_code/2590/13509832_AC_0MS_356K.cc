#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int n, m, t, x, p;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		x = abs(n - m);
		n = (-1 + sqrt(1 + 4 * x))/2;
		p = x - n * (n + 1);
		if(p > n + 1)
			printf("%d\n", 2 * n + 2);
		else if(!p)
			printf("%d\n", 2 * n);
		else
			printf("%d\n", 2 * n + 1);
	}
	return 0;
}