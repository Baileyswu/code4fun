#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int F, V, set[105], ans[105], t[105];
	while(~scanf("%d%d", &F, &V))
	{
		memset(ans, 0, sizeof(ans));
		for(int j = 0;j < V;j++)
			scanf("%d", &set[j]);
		ans[0] = set[0];
		for(int j = 1;j < V;j++)
			ans[j] = max(set[j], ans[j-1]);
		for(int i = 1;i < F;i++)
		{
			for(int j = 0;j < V;j++)
				scanf("%d", &set[j]);
			t[i] = ans[i-1]+set[i];
			for(int j = i+1;j < V;j++)
				t[j] = max(ans[j-1]+set[j], t[j-1]);
			for(int j = i;j < V;j++)
				ans[j] = t[j];
		}
		printf("%d\n", ans[V-1]);
	}
	return 0;
}