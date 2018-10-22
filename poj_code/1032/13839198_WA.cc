#include <stdio.h>
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		if(n&1LL)
			printf("%d %d\n", n/2, n/2+1);
		else
			printf("%d %d\n", n/2-1, n/2+1);
	}
	return 0;
}