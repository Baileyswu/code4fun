#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}
int main()
{
	int n, i, a[101];
	double ans;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%d", &a[i]);
	if(n == 1)
		printf("%d\n", a[0]);
	else
	{
		sort(a, a+n, cmp);
		ans = pow(2, 2*(1-pow(1.0/2, n - 1)));
		for(i = 0;i < n - 1;i++)
			ans *= pow(a[i], pow(1.0/2, i+1.0));
		ans *= pow(a[n - 1], pow(1.0/2, n - 1));
		printf("%.3lf\n", ans);
	}
	return 0;
}