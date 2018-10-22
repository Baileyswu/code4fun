#include <stdio.h>
int main()
{
	int W, a, b, fa, fb, la, lb;
	while(scanf("%d", &W), W)
	{
		fa = fb = la = lb = 0;
		while(scanf("%d%d", &a, &b), a != -1 && b != -1)
		{
			if(la + a <= W)
			{
				la += a;
				if(b > lb)
					lb = b;
			}
			else
			{
				if(la > fa)
					fa = la;
				la = a;
				fb += lb;
				lb = b;
			}
		}
		if(la > fa)
			fa = la;
		fb += lb;
		printf("%d x %d\n", fa, fb);
	}
	return 0;
}