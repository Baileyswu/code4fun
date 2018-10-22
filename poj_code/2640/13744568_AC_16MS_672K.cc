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
		double a[25], sum = 0, tmp;
		int i, v = 0;
		for(i = 0;i < n;i++)
			scanf("%lf", &a[i]);
		sort(a, a+n, cmp);
		for(i = 0;i < n;i++)
		{
			tmp = a[i] - sum;
			if(!(tmp > 0))
			{
				printf("YES\n");
				v = 1;
				break;
			}
			sum += a[i];
		}
		if(!v)
			printf("NO\n");
	}
	return 0;
}