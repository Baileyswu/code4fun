#include <stdio.h>
int main()
{
	int t, n, a[10005], i, point, sum, temp;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		sum = 0;
		for(i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		for(i = 1;i <= n;i++)
		{
			point = i;
			while(a[point] && a[point] != i)
			{
				temp = point;
				point = a[point];
				a[temp] = 0;
				sum++;
			}
			a[point] = 0;
		}
		printf("%d\n", sum);
	}
	return 0;
}