#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int F, V, set[105][105], ans[105], t[105];
	while(~scanf("%d%d", &F, &V))
	{
		for(int i = 0;i < F;i++)
			for(int j = 0;j < V;j++)
				scanf("%d", &set[i][j]);
		memset(ans, 0, sizeof(ans));
		ans[0] = set[0][0];
		for(int j = 1;j < V;j++)
			ans[j] = max(set[0][j], ans[j-1]);
		for(int i = 1;i < F;i++)
		{
			t[i] = ans[i-1]+set[i][i];
			for(int j = i+1;j < V;j++)
				t[j] = max(ans[j-1]+set[i][j], t[j-1]);
			for(int j = i;j < V;j++)
				ans[j] = t[j];
		}
		printf("%d\n", ans[V-1]);
	}
	return 0;
}