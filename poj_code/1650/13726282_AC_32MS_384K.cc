#include <stdio.h>
int main()
{
	double a;
	int wide;
	while(~scanf("%lf%d", &a, &wide))
	{
		int x = 1, y = 1, ax, ay;
		double j = 1, mimi = wide;
		while(x <= wide && y <= wide)
		{
			j = 1.0*x/y;
			if(j >= a)
			{
				if(j-a<mimi)
				{
					mimi = j-a;
					ax = x;
					ay = y;
				}
				y++;
			}
			else
			{
				if(a-j<mimi)
				{
					mimi = a-j;
					ax = x;
					ay = y;
				}
				x++;
			}
		}
		printf("%d %d\n", ax, ay);
	}
	return 0;
}