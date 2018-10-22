#include <stdio.h>
#include <math.h>
#define Pi 3.1415926535898
int main()
{
	double x1,y1,r1,x2,y2,r2;
	while(~scanf("%lf%lf%lf%lf%lf%lf", &x1,&y1,&r1,&x2,&y2,&r2))
	{
		double d = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		if(d >= r1 + r2)
		{
			printf("0.000\n");
			continue;
		}
		if(d <= fabs(r1-r2))
		{
			double r = r1 < r2?r1:r2;
			printf("%.3f\n", Pi*r*r);
			continue;
		}
		double g1 = 2*acos((d*d+r1*r1-r2*r2)/(2*d*r1));
		double g2 = 2*acos((d*d+r2*r2-r1*r1)/(2*d*r2));
		double s = (r1*r1*(g1-sin(g1)) + r2*r2*(g2-sin(g2)))/2;
		printf("%.3f\n", s);
	}
	return 0;
}