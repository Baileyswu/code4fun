#include <cstdio>
#include <algorithm>
using namespace std;
int cmp(double x, double y)
{
	return x > y;
}
int main()
{
	int n, m, f[10], r[100];
	double a[300];
	while(scanf("%d",&n), n)
	{
		scanf("%d", &m);
		for(int i = 0;i < n;i++)
			scanf("%d", &f[i]);
		for(int j = 0;j < m;j++)
			scanf("%d", &r[j]);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				a[i*m+j] = 1.0*r[j]/f[i];
		sort(a, a+n*m, cmp);
		for(int i = 0;i < n*m-1;i++)
			a[i] = a[i]/a[i+1];
		a[n*m-1] = 0;
		sort(a, a+n*m, cmp);
		printf("%.2f\n", a[0]);
	}
	return 0;
}
