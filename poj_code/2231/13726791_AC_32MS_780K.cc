#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int co[10010], num[10010];
int cmp(int x, int y)
{
	return  x < y;
}
int main()
{
	int n, i;
	while(~scanf("%d", &n))
	{
		long long sum = 0;
		for(i = 0;i < n;i++)
			scanf("%d", &num[i]);
		sort(num, num+n, cmp);
		memset(co, 0, sizeof(co));
		for(i = 0;i < n-1;i++)
			num[i] = num[i+1]-num[i];
		for(i = 0;i < n/2;i++)
			co[i] = (i+1)*(n-1-i);
		for(;i < n-1;i++)
			co[i] = co[n-2-i];
		for(i = 0;i < n;i++)
			sum +=(long long) num[i]*co[i];
		printf("%lld\n", sum*2);
	}
	return 0;
}
