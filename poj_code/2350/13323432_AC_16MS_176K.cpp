#include <stdio.h>
int a[1000];
int main()
{
	int t, n, i, count;
	double sum;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		sum = 0.0, count = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sum /= n;
		for(i = 0;i < n;i++)
			if(a[i] > sum)
				count++;
		printf("%.3lf%%\n", 1.0*count/n * 100);
	}
	return 0;
}