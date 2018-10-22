#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int cmp(int a, int b)
{
	return a < b;
}
int main()
{
	int t, n, a[1005], i, max, tmp;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 0;i<n;i++)
			scanf("%d", &a[i]);
		sort(a, a+n, cmp);
		max = 0;
		for(int i = 0;i < n;i++)
		{
			tmp = a[i] * (n - i);
			if(tmp > max)
				max = tmp;
		}
		printf("%d\n", max);
	}
	return 0;
}