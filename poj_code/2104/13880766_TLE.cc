#include <cstdio>
#include <algorithm>
using namespace std;
int num[100010], so[100010];
int cmp(int x, int y)
{
	return x < y;
}
int main()
{
	int n, m, a, b, c;
	while(~scanf("%d%d", &n, &m))
	{
		for(int i = 0;i < n;i++)
			scanf("%d", &num[i]);
		while(m--)
		{
			scanf("%d%d%d", &a, &b, &c);
			for(int i = 0;i < b-a+1;i++)
				so[i] = num[i+a-1];
			sort(so, so+b-a+1, cmp);
			printf("%d\n", so[c-1]);
		}
	}
	return 0;
}
