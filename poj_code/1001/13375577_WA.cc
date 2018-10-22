#include <stdio.h>
#include <math.h>
long long re[155];
int pr(int x, int y)
{
	for(int i = x;i >= y;i--)
		printf("%lld", re[i]);
}
int main()
{
	double R;
	int r, i, n, start, end, k;
	long long t;
	while(~scanf("%lf%d", &R, &n))
	{
		k = log(R)/log(10) + 1;
		if(!k)
			k = 1;
		k = 5 - k;
		R *= pow(10, k);
		r = (int)R, k *= n;
		for(i = 1;i < 155;i++)
			re[i] = 0;
		re[0] = r;
		n--;
		while(n--)
		{
			for(i = 0;i < 155;i++)
				re[i] *= r;
			for(i = 0;i < 155;i++)
			{
				t = re[i]/10;
				re[i] %= 10;
				re[i + 1] += t;
			}
		}
		for(i = 154;i >= 0;i--)
		{
			if(re[i])
			{
				start = i;
				break;
			}
		}
		for(i = 0;i <= start;i++)
		{
			if(re[i])
			{
				end = i;
				break;
			}
		}
		if(k > end)
		{
			if(k < start + 1)
			{
				pr(start, k);
				printf(".");
				pr(k - 1, end);
				printf("\n");
			}
			if(k >= start + 1)
			{
				printf(".");
				for(i = 0;i < k - start - 1;i++)
					printf("0");
				pr(start, end);
				printf("\n");
			}
		}
		if(k <= end)
		{
			pr(start, k);
			printf("\n");
		}
	}
	return 0;
}