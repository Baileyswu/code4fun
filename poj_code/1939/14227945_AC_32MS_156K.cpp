#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
int num[1005][4], p[55][4];
using namespace std;
struct node
{
	double x, y;
}first, a, b;
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		printf("%d", n);
		scanf("%lf%lf", &first.x, &first.y);
		a = first;
		while(n-- > 1)
		{
			scanf("%lf%lf", &b.x, &b.y);
			printf(" %.6f %.6f", 0.5*(a.x+b.x), 0.5*(a.y+b.y));
			a = b;
		}
		printf(" %.6f %.6f\n", 0.5*(first.x+b.x), 0.5*(first.y+b.y));
	}
	return 0;
}