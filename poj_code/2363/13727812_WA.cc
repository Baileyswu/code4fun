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
		int x = (int )a, y, z, ans;
		//printf("%lf %d\n", a, x);
		if(x*x*x==a)
		{
			printf("%d\n", 6*x*x);
			continue;
		}
		int mimi = 1000000000;
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
				ans = 2*(x*y+y*z+z*x);
			}
			if(ans < mimi)
			{
				mimi = ans;
				//printf("(%d %d %d)\n", x, y, z);
			}
		}
		printf("%d\n", mimi);
	}
	return 0;
}
