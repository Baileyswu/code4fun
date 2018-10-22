#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int cmp(int x, int y)
{
	return x < y;
}
int main()
{
	int n, a[105];
	while(scanf("%d", &n), n)
	{
		int i, sum = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a, a+n, cmp);
		sum -= a[0] + a[n-1];
		sum /= n-2;
		printf("%d\n", sum);
	}
	return 0;
}