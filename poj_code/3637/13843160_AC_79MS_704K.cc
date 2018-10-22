#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int x, int y)
{
	return x > y;
}
int main()
{
	int t, n, a[20010];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", &a[i]);
		sort(a, a+n, cmp);
		int ans = 0;
		for(int i = 0;i < n;i++)
			if(i%3==2)
				ans += a[i];
		printf("%d\n", ans);
	}
	return 0;
}