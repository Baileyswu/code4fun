#include <stdio.h>
#include <math.h>
#define ep 10e-9
int main()
{
	int c, d;
	double a, b, ans;
	while(~scanf("%lf%lf%d%d", &a, &b, &c, &d))
	{
		if(a<ep && b<ep && !c && !d)
			break;
		ans = -log((sqrt(pow(a,2.0)+4.0*a*b*c*d)-a)/(2.0*d))/log(10);
		printf("%.3f\n", ans);
	}
	return 0;
}