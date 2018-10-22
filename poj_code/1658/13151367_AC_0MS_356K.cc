#include <stdio.h>
int main()
{
	int t, a[4], d;
	scanf("%d", &t);
	while(t--)
	{
		for(int i = 0;i < 4;i++)
			scanf("%d", &a[i]);
		d = a[1] - a[0];
		if(a[2] - a[1] == d && a[3] - a[2] == d)
		{
			for(int i = 0;i < 4;i++)
				printf("%d ", a[i]);
			printf("%d\n", a[3] + d);
			continue;
		}
		d = a[1]/a[0];
		for(int i = 0;i < 4;i++)
			printf("%d ", a[i]);
		printf("%d\n", a[3] * d);
	}
	return 0;
}