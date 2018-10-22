#include <stdio.h>
#include <math.h>
int main()
{
	double r, m;
	int y;
	scanf("%lf%lf%d", &r, &m, &y);
	r = 1 + r / 100;
	m = pow(r, y) * m;
	printf("%.d\n", (int)m);
	return 0;
}