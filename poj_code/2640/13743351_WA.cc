#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int cmp(double a, double b)
{
	return a < b;
}
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		double a[25], sum = 0;
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%lf", &a[i]);
			sum += a[i];
		}
		sort(a, a+n, cmp);
		sum -= a[n-1];
		sum = a[n-1]-sum;
		if(sum > 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}