#include <stdio.h>
#include <math.h>
#define inf 1e-8
#define eps 1e-4
int main()
{
	double sit[19901][2];
	int n, a[201][2], i, j, z, tem, max;
	bool flag[19901];
	while(scanf("%d", &n)!= EOF && n)
	{
		z = 0, max = 0;
		for(i = 0;i < n;i++)
			scanf("%d%d", &a[i][0], &a[i][1]);
		for(i = 0;i < n - 1;i++)
			for(j = i + 1;j < n;j++)
			{
				if(a[i][0] == a[j][0])
					sit[z][0] = inf, sit[z][1] = 0;
				else
				{
					sit[z][0] = 1.0 * (a[i][1] - a[j][1])/(a[i][0] - a[j][0]);
					sit[z][1] = a[i][1] - sit[z][0] * a[i][0];
				}
				flag[z] = true;
				z++;
			}
		for(i = 0;i < z;i++)
		{
			if(flag[i])
			{
				tem = 0;
				for(j = i;j < z;j++)
				{
					if(fabs(sit[j][0] - sit[i][0]) < eps && fabs(sit[j][1] - sit[i][1]) < eps)
						tem++;
					flag[j] = 0;
				}
				if(tem > max)
					max = tem;
			}
		}
		max = (1 + sqrt(1 + 8 * max))/2;
		printf("%d\n", max);
	}
	return 0;
}