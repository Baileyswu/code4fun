#include <stdio.h>
int main()
{
	int t, n, m;
	scanf("%d", &t);
	m = t;
	while(t--)
	{
		scanf("%d", &n);
		printf("%d %d %lld\n", m - t, n, n*(n+1)*(n+2)*(n+3)/8);
	}
	return 0;
}