#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node 
{
	int a, b;
}day[105];
int set()
{
	for(int i = 0;i < 105;i++)
	{
		day[i].a = i;
		day[i].b = 0;
	}
}
int cmp(struct node x, struct node y)
{
	return x.b > y.b || (x.b==y.b && x.a < y.a);
}
int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m))
	{
		if(!n && !m)
			break;
		set();
		int q, num, ans = 0;
		while(n--)
		{
			scanf("%d", &q);
			while(q--)
			{
				scanf("%d", &num);
				day[num].b++;
			}
		}
		sort(day, day+105, cmp);
		if(day[0].b >= m)
			ans = day[0].a;
		printf("%d\n", ans);
	}
	return 0;
}