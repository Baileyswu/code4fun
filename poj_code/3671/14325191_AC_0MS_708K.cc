#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define maxn 50005
int num[maxn];
int ok(int x)
{
	return x == 1 ? 1 : 0;
}
int main()
{
	int n, num;
	while(~scanf("%d", &n))
	{
		int a[2] = {0, 0}, b[2] = {0, 0};
		while(n--)
		{
			scanf("%d", &num);
			a[0] = min(b[0], b[1]) + ok(num);
			a[1] = b[1] + 1 - ok(num);
			b[0] = a[0], b[1] = a[1];
			//printf("-----%d  %d\n", a[0], a[1]);
		}
		int ans = min(b[0], b[1]);
		printf("%d\n", ans);
	}
	return 0;
}