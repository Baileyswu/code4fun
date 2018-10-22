#include <stdio.h>
int main()
{
	int n, m, p, c;
	while(scanf("%d%d%d%d", &n, &m, &p, &c) && n)
		printf("%d\n", n - m + p);
	return 0;
}