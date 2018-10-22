#include <cstdio>
#include <algorithm>
using namespace std;
int hi[20010];
int cmp(int x, int y)
{
	return x > y;
}
int main()
{
	int n, b;
	while(~scanf("%d%d", &n, &b))
	{
		for(int i = 0;i < n;i++)
			scanf("%d", &hi[i]);
		sort(hi, hi+n, cmp);
		int ans = 0, h = 0, p = 0;
		while(h < b)
			h += hi[p++];
		printf("%d\n", p);
	}
	return 0;
}