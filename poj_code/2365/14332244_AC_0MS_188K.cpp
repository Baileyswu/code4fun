#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define Pi  3.1415926535898
struct node
{
	double x, y;
}p1, p2, pt;
double dis(struct node p, struct node q)
{
	return sqrt(pow(p.x-q.x, 2) + pow(p.y-q.y, 2));
}
int main()
{
	int n;
	double r;
	while(~scanf("%d%lf", &n, &r))
	{
		double sum = 2.0*r*Pi;
		scanf("%lf%lf", &p1.x, &p1.y);
		pt = p1;
		n--;
		while(n--)
		{
			scanf("%lf%lf", &p2.x, &p2.y);
			sum += dis(p1, p2);
			p1 = p2;
		}
		sum += dis(p1, pt);
		printf("%.2f\n", sum);
	}
	return 0;
}