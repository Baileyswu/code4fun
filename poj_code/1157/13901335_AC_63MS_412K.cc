#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int F, V, set[105][105], ans[105][105];
	while(~scanf("%d%d", &F, &V))
	{
		for(int i = 0;i < F;i++)
			for(int j = 0;j < V;j++)
				scanf("%d", &set[i][j]);
		memset(ans, 0, sizeof(ans));
		ans[0][0] = set[0][0];
		for(int j = 1;j < V;j++)
			ans[0][j] = max(set[0][j], ans[0][j-1]);
		for(int i = 1;i < F;i++)
		{
			ans[i][i] = ans[i-1][i-1]+set[i][i];
			for(int j = i+1;j < V;j++)
				ans[i][j] = max(ans[i-1][j-1]+set[i][j], ans[i][j-1]);
		}
		printf("%d\n", ans[F-1][V-1]);
	}
	return 0;
}