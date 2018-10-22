#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define e 2.718281828459
int main()
{
	int b, n, a, s1, s2;
	while(scanf("%d%d", &b, &n) && b && n)
	{
		double x = pow(e, log(b)/n);
		a = floor(x);
		s1 = pow(a, n);
		if(s1 == n)
		{
			printf("%d\n", a);
			continue;
		}
		a += 1;
		s2 = pow(a, n);
		if(fabs(s2 - b) < fabs(s1 - b))
			printf("%d\n", a);
		else
			printf("%d\n", a - 1);
	}
	return 0;
}