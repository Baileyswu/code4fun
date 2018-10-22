#include <stdio.h>
#include <string.h>
int x[15], y[15], z[15];
int main()
{
	char a[15];
	scanf("%s", a);
	int d = strlen(a), i;
	for(i = 0;i < d;i++)
	{
		x[i] = a[d - 1 - i] - '0';
		z[i] = a[d - 1 - i] - '0';
	}
	while(~scanf("%s", a))
	{
		for(i = 0;i < d;i++)
			y[i] = a[d - 1- i] - '0';
		for(i = 0;i < d;i++)
			z[i] = x[i] + y[i];
		for(i = 0;i < d;i++)
			if(z[i] > 9)
				z[i] -= 10;
		for(i = 0;i < d;i++)
			x[i] = z[i];
	}
	for(i = d - 1;i >= 0;i--)
		printf("%d", z[i]);
	printf("\n");
	return 0;
}