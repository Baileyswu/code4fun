#include <stdio.h>
int main()
{
	int t, n, a[13], k, i, step;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			a[i] = 0;
		k = -1;
		for(i = 1;i <= n;i++)
		{
			step = i + 1;
			while(step--)
			{
				k++;
				k %= n;
				if(a[k])
					step++;
			}
			a[k] = i;
		}
		for(i = 0;i < n;i++)
			printf("%d ", a[i]);
		printf("\n");
	}
}