#include <stdio.h>
int gcd(int n, int m)
{
	if(!n)
		return m;
	if(!m)
		return n;
	return gcd(m, n%m);
}
int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		if(gcd(n, m)==1)
			printf("%10d%10d    Good Choice\n\n", n, m);
		else
			printf("%10d%10d    Bad Choice\n\n", n, m);
	}
	return 0;
}