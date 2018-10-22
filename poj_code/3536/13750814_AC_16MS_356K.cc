#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int min = 4*n+2, xi = 1, yi = 1, zi = n;
		for(int i = 1;i <= sqrt(n)+1;i++)
		{
			if(n%i)
				continue;
			int m = n/i;
			for(int j = 1;j <= sqrt(m)+1;j++)
			{
				if(m%j)
					continue;
				int k = m/j;
				int s = 2*(i*j+j*k+k*i);
				if(s < min)
				{
					min = s;
					xi = i, yi = j, zi = k;
				}
			}
		}
		printf("%d %d %d\n", xi, yi, zi);
	}
	return 0;
}
