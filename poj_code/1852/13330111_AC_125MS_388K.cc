#include <stdio.h>
#include <math.h>
int main()
{
	int t, len, n, x;
	double min, max, temp, mid;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &len, &n);
		mid = len / 2.0;
		min = mid, max = 0;
		while(n--)
		{
			scanf("%d", &x);
			temp = fabs(0.0 + mid - x);
			if(temp > max)
				max = temp;
			if(temp < min)
				min = temp;
		}
		printf("%.0f %.0f\n", mid - min, mid + max);
	}
	return 0;
}