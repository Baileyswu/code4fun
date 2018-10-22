#include <stdio.h>
#include <math.h>
int gcd(int a, int b)
{
	if(!a)
		return b;
	if(!b)
		return a;
	return gcd(b, a%b);
}
int main()
{
	int wide, m, n, i, x, y;
	double a;
	while(~scanf("%lf%d", &a, &wide))
	{
		if(a < 1)
			a = 1/a;
		double mimi = wide, ever, temp;
		int mx, my, ex, ey;
		for(m = 1;m <= wide;m++)
		{
			ever = wide;
			for(n = 1;n <= m;n++)
			{
				temp = fabs(a - 1.0*m/n);
				if(temp > ever)
				{
					ex = m, ey = n-1;
					break;
				}
				ever = temp;
			}
			if(ever < mimi)
			{
				mx = ex, my = ey;
				mimi = ever;
				//printf("~~~%d %d\n", mx, my);
			}
			//printf("watch: %d %d\n", ex, ey);
		}
		printf("%d %d\n", mx, my);
	}
	return 0;
}
