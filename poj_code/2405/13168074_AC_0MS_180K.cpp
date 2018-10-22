#include <stdio.h>
#include <math.h>
#define Pi 3.141592653589793
int main()
{
	double d, v;
	while(scanf("%lf%lf", &d, &v) && d && v)
	{
		double ans = pow(pow(d, 3) - 6 * v / Pi, 1.0 / 3);
		printf("%.3lf\n", ans);
	}
	return 0;
}