#include <stdio.h>
long long divide(int n, int m, int l)
{
	if(m > n)
		return divide(n, n, l) % 1000000007;
	if(m == 1 || n == l)
		return 1;
	int s = 1;
	for(int i = l;i <= n/2;i++)
		s = s + divide(n - i, m - 1, i) % 1000000007;
	return s % 1000000007;
}
int main()
{
	int t, n, m;
	while(~scanf("%d%d", &m, &n))
		printf("%lld\n", divide(n, m, 1));
	return 0;
}