#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int x, y;
	double z;
}a[3405];
int cmp(struct node m, struct node n)
{
	return m.z > n.z;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].z = 1.0*a[i].y/a[i].x;
	}
	sort(a, a+n, cmp);
	int p = 0;
	double ans = 0;
	while(m > 0)
	{
		if(a[p].x <= m)
		{
			m -= a[p].x;
			ans += a[p].y;
		}
		else
		{
			m = 0;
			ans += m*a[p].z;
		}
		p++;
	}
	printf("%.0f\n", ans);
	return 0;
}