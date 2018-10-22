#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1005];
int cmp(int x, int y)
{
	return x < y;
}
int find()
{
	int s;
	if(2 * a[1] - a[0] - a[n - 2] < 0)
		s = a[0] + 2 * a[1] + a[n - 1];
	else
		s = 2 * a[0] + a[n - 1] + a[n - 2];
	n -= 2;
	return s;
}
int main()
{
	int t, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%d", &a[i]);
		sort(a, a + n, cmp);
		int ans = 0;
		while(n > 3)
			ans += find();
		switch(n)
		{
			case 1: ans += a[0];break;
			case 2: ans += a[1];break;
			case 3: ans += a[0] + a[1] + a[2];break;
		}
		printf("%d\n", ans);
	}
	return 0;
}