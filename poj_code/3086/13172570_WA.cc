#include <stdio.h>
int main()
{
	int t, m;
	long long ans, n;
	scanf("%d", &t);
	m = t;
	while(t--)
	{
		scanf("%lld", &n);
		ans = n*(n+1)*(n+2)*(n+3)/8;
		printf("%d %d %lld\n", m - t, n, ans);
	}
	return 0;
}