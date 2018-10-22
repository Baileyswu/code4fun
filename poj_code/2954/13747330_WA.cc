#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
	if(!a)
		return b;
	if(!b)
		return a;
	return gcd(b, a%b);
}
int g(int a, int b)
{
	a = abs(a), b = abs(b);
	return gcd(a, b)+1;
}
int main()
{
	int a, b, c, d, e, f;
	while(~scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f))
	{
		if(!a && !b && !c && !d && !e && !f)
			break;
		c -= a, d -= b, e -= a, f -= b;
		double s = fabs(1.0*(c*f-e*d)/2);
		int count = g(c, d) + g(e, f) + g(e-c, f-d) - 3;
		double ans = s+1-count/2.0;
		printf("%.0lf\n", ans);
	}
	return 0;
}
