#include <stdio.h>
int main()
{
	int L, M, a, b;
	while(scanf("%d%d", &L, &M) && L && M)
	{
		L++;
		while(M--)
		{
			scanf("%d%d", &a, &b);
			L -= b - a + 1;
		}
		printf("%d\n", L);
	}
	return 0;
}