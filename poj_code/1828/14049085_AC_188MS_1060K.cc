#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node
{
	int x, y;
}node;
node p[50005], tp;
int cmp(node a, node b)
{
	return a.x > b.x || (a.x==b.x && a.y > b.y);
}
int main()
{
	int t;
	while(scanf("%d", &t), t)
	{
		for(int i = 0;i < t;i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		sort(p, p+t, cmp);
		tp.x = p[0].x+1, tp.y = p[0].y-1;
		int ans = 0;
		for(int i = 0;i < t;i++)
		{
			if(p[i].x < tp.x && p[i].y > tp.y)
			{
				tp = p[i];
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}