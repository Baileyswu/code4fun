#include <stdio.h>
#include <math.h>
int main()
{
	char c1[2];
	double t,d,h,e;
	while(scanf("%s", c1) && c1[0] != 'E')
	{
		scanf("%lf%s%lf", &t, c1, &d);
		printf("T %.1lf D %.1lf ", t, d);
		e = 6.11 * pow(2.718281828, (5417.7530 * ((1/273.16) - (1/(d+273.16)))));
		h = (0.5555)* (e - 10.0);
		t = t + h;
		printf("H %.1lf\n", t);
	}
	return 0;
}