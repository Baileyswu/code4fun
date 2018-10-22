#include <stdio.h>
#include <math.h>
#define Pi 3.14159265358979
int main()
{
	int t, ans;
	double D, d, s;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lf%lf%lf", &D, &d, &s);
		d = 2.0*asin((s+d)/(D-d));
		ans = 2*Pi/d;
		printf("%d\n", ans);
	}
	return 0;
}