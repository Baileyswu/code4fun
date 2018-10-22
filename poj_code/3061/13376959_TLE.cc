#include <stdio.h>
int a[100000];
int main()
{
	int t;
	while(~scanf("%d", &t))
	{
		int n, sum, i, min, j, hi;
		while(t--)
		{
			scanf("%d%d", &n, &sum);
			min = n;
			for(i = 0;i < n;i++)
				scanf("%d", &a[i]);
			for(i = 0;i < n;i++)
			{
				hi = 0;
				for(j = i;j < n;j++)
				{
					hi += a[j];
					if(hi >= sum)
					{
						j = j - i + 1;
						if(j < min)
							min = j;
						break;
					}
				}
			}
			printf("%d\n", min);
		}
	}
	return 0;
}