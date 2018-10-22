#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define Pi acos(-1)
int main()
{
	int n, r;
	while(~scanf("%d%d", &n, &r))
	{
		double sum = 0, x1, y1, x2, y2;
		scanf("%lf%lf", &x1, &y1);
		double px = x1, py = x2;
		n--;
		while(n--)
		{
			scanf("%lf%lf", &x2, &y2);
			sum += sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
			x1 = x2, y1 = y2;
		}
		x2 = px, y2 = py;
		sum += sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
		sum += 2.0*r*Pi;
		printf("%.2f\n", sum);
	}
	return 0;
}