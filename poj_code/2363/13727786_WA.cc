#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		double a = pow(n+1, 1.0/3);
		int x = (int )a, y, z;
		if(x*x*x==a)
		{
			printf("%d\n", 6*x*x);
			continue;
		}
		for(;x > 0;x--)
		{
			if(n%x == 0)
			{
				int m = n/x;
				for(y = sqrt(m);y > 0;y++)
					if(m%y == 0)
					{
						z = m/y;
						break;
					}
				break;
			}
		}
		printf("%d\n", 2*(x*y+y*z+z*x));
	}
	return 0;
}
