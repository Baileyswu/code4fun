#include <stdio.h>
int main()
{
	int a[33], n, i, sum, s;
	while(scanf("%d", &n), n)
	{
		sum = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if(sum & 1LL)
			printf("No equal partitioning.\n");
		else
		{
			sum >>= 1;
			s = 0;
			for(i = 0;i < n;i++)
			{
				if(s < sum)
					s += a[i];
				else
					break;
			}
			if(s > sum)
				printf("No equal partitioning.\n");
			else if(s == sum)
				printf("Sam stops at position %d and Ella stops at position %d.\n", i, i+1);
		}
	}
	return 0;
}