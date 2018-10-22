#include <stdio.h>
int main()
{
	int n, count, max = 0, x, point = 1;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		count = 0;
		for(int j = 0;j < n;j++)
		{
			scanf("%d", &x);
			count += x;
		}
		if(count > max)
		{
			max = count;
			point = i + 1;
		}
	}
	printf("%d\n", point);
	return 0;
}