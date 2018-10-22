#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int lug[3410][2], ans[3410][12890];
int main()
{
	int n, c;
	while(~scanf("%d%d", &n, &c))
	{
		for(int i = 1;i <= n;i++)
			scanf("%d%d", &lug[i][0], &lug[i][1]);
		memset(ans, 0, sizeof(ans));
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j <= c;j++)
			{
				if(lug[i][0] <= j)
					ans[i][j] = max(ans[i-1][j], ans[i-1][j-lug[i][0]]+lug[i][1]);
				else
					ans[i][j] = ans[i-1][j];
			}
		}
		printf("%d\n", ans[n][c]);
	}
	return 0;
}