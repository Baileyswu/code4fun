#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		if(n > 199)
			printf("0\n");
		else
		{
			int ans = min(99, n) - max(0, n-99) + 1;
			printf("%d\n", ans);
		}
	}
	return 0;
}
