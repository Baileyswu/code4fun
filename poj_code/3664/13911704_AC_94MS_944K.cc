#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int first, second, p;
}player[50010];
int cmp1(struct node x, struct node y)
{
	return x.first < y.first;
}
int cmp2(struct node x, struct node y)
{
	return x.second > y.second;
}
int main()
{
	int n, k;
	while(~scanf("%d%d", &n, &k))
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%d%d", &player[i].first, &player[i].second);
			player[i].p = i+1;
		}
		sort(player, player+n, cmp1);
		for(int i = 0;i < n-k;i++)
			player[i].second = 0;
		sort(player, player+n, cmp2);
		printf("%d\n", player[0].p);
	}
	return 0;
}
