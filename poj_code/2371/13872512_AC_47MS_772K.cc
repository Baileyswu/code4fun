#include <cstdio>
#include <algorithm>
using namespace std;
int num[100010];
int cmp(int x, int y)
{
	return x < y;
}
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		for(int i = 0;i < n;i++)
			scanf("%d", &num[i]);
		sort(num, num+n, cmp);
		char c[10];
		scanf("%s", c);
		int m, d;
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &d);
			printf("%d\n", num[d-1]);
		}
	}
	return 0;
}