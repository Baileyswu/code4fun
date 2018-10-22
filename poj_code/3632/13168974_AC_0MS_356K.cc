#include <stdio.h>
int main()
{
	int min, max, t, n, x;
	scanf("%d", &t);
	while(t--)
	{
		min = 99, max = 0;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &x);
			if(x < min)
				min = x;
			if(x > max)
				max = x;
		}
		printf("%d\n", 2*(max - min));
	}
	return 0;
}