#include <cstdio>
#include <algorithm>
using namespace std;
int cow[20010];
int cmp(int x, int y)
{
	return x < y;
}
int main()
{
	int n, s;
	while(~scanf("%d%d", &n, &s))
	{
		for(int i= 0;i < n;i++)
			scanf("%d", &cow[i]);
		sort(cow, cow+n, cmp);
		int p = n-1, ans = 0;
		for(int i = 0;i < n;i++)
		{
			if(p <= i)
				break;
			while(cow[p] > s-cow[i])
				p--;
			if(p <= i)
				break;
			ans += p-i;
		}
		printf("%d\n", ans);
	}
	return 0;
}