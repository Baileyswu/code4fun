#include <stdio.h>
#include <math.h>
#define Pi 3.141592653589793
int main()
{
	int t, p = 0;
	scanf("%d", &t);
	while(t--)
	{
		double r, n;
		scanf("%lf%lf", &r, &n);
		if(n == 1)
		{
			printf("Scenario #%d:\n%.3lf\n\n", ++p, r);
			continue;
		}
		n = Pi/n;
		printf("Scenario #%d:\n%.3lf\n\n", ++p, r*sin(n)/(1 + sin(n)));
	}
	return 0;
}