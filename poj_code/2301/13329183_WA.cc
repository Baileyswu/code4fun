#include <stdio.h>
int main()
{
	int t, a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &a, &b);
		if(a < b)
			printf("impossible\n");
		else
			printf("%d %d\n", a + b >> 1, a - b >> 1);
	}
	return 0;
}