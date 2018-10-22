#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int day[105];
int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m))
	{
		if(!n && !m)
			break;
		memset(day, 0, sizeof(day));
		int q, num, ans = 0;
		while(n--)
		{
			scanf("%d", &q);
			while(q--)
			{
				scanf("%d", &num);
				day[num]++;
				if(!ans && day[num] >= m)
					ans = num;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}