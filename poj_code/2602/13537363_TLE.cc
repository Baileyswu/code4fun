#include <stdio.h>
int a[1000005];
int main()
{
	int t, x, y, i;
	scanf("%d", &t);
	for(i = 0;i < t;i++)
	{
		scanf("%d%d", &x, &y);
		a[i] = x + y;
	}
	for(i = t - 1;i >= 0;i--)
		if(a[i] > 9)
		{
			a[i] -= 10;
			a[i - 1]++;
		}
	for(i = 0;i < t;i++)
		printf("%d", a[i]);
	printf("\n");
	return 0;
}