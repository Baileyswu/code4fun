#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define maxn 50005
int num[maxn];
int cmp(int x, int y)
{
	return abs(x) < abs(y);
}
int main()
{
	int T, n;
	while(~scanf("%d%d", &T, &n))
	{
		num[0] = 0;
		for(int i = 1;i <= n;i++)
			scanf("%d", &num[i]);
		sort(num, num+n+1, cmp);
		int p = 0;
		for(int i = 1;i <= n;i++)
		{
			p += abs(num[i] - num[i-1]);
			if(p > T)
			{
				printf("%d\n", i-1);
				break;
			}
		}
		if(p <= T)
			printf("%d\n", n);
	}
	return 0;
}
