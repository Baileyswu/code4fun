#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int lug[3410][2], ans[12890], no[12890];
int main()
{
	int n, c;
	while(~scanf("%d%d", &n, &c))
	{
		for(int i = 1;i <= n;i++)
			scanf("%d%d", &lug[i][0], &lug[i][1]);
		memset(ans, 0, sizeof(ans));
		memset(no, 0, sizeof(no));
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j <= c;j++)
			{
				if(lug[i][0] <= j)
				{
					no[j] = max(ans[j], ans[j-lug[i][0]]+lug[i][1]);
				}
			}
			for(int j = 0;j <= c;j++)
				ans[j] = no[j];
		}
		printf("%d\n", ans[c]);
	}
	return 0;
}