#include <stdio.h>
int main()
{
	int n, a0, a1;
	while(scanf("%d", &n) && n)
	{
		a0 = 0, a1 = -1;
		while(!(n & 1LL))
		{
			a0++;
			n >>= 1;
		}
		while(n & 1LL)
		{
			a1++;
			n >>= 1;
		}
		n++;
		n <<= 1;
		while(a0--)
			n <<= 1;
		while(a1 > 0 && a1--)
		{
			n <<= 1;
			n++;
		}
		printf("%d\n", n);
	}
}