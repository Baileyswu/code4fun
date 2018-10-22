#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	double x, y;
}p0, p, pa, pb;
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		if(n < 3)
		{
			while(n--)
				scanf("%lf%lf", &p0.x, &p0.y);
			printf("0\n");
			continue;
		}
		scanf("%lf%lf%lf%lf", &p0.x, &p0.y, &p.x, &p.y);
		pa.x = p.x - p0.x, pa.y = p.y - p0.y;
		n -= 2;
		double ans = 0;
		while(n--)
		{
			scanf("%lf%lf", &p.x, &p.y);
			pb.x = p.x - p0.x, pb.y = p.y - p0.y;
			ans += fabs(1.0*(pa.x*pb.y-pa.y*pb.x)/2.0);
			pa = pb;
		}
		printf("%d\n", (int)ans);
	}
	return 0;
}
