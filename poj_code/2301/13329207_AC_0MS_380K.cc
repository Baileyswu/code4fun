#include <stdio.h>
int main()
{
	int t, a, b, c, d;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &a, &b);
		if(a < b)
			printf("impossible\n");
		else
		{	
			c = a + b >> 1, d = a - b >> 1;
			if(c + d != a || c - d != b)
				printf("impossible\n");
			else
				printf("%d %d\n", c, d);
		}
	}
	return 0;
}