#include <stdio.h>
#define Pi 3.1415927
int main()
{
	double a, c;
	int b, p = 0;
	while(scanf("%lf%d%lf", &a, &b, &c), b)
	{
		double dis = Pi * a * b / 5280 / 12;
		double v = Pi * a * b * 3600 / 5280 / 12 / c;
		printf("Trip #%d: %.2f %.2f\n", ++p, dis, v);
	}
	return 0;
}