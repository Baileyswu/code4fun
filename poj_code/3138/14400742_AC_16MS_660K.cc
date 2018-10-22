#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
struct node
{
	int a, b, c, ok;
	int num;
	void pr()
	{
		printf("%d %d %d %d\n", b, c, ok, num);
	}
}school[105];
int main()
{
	int Sch, Tea, Min_, o = 0;
	while(~scanf("%d%d%d", &Sch, &Tea, &Min_))
	{
		memset(school, 0, sizeof(school));
		if(!Sch && !Tea && !Min_)
			break;
		for(int i = 0;i < Sch;i++)
		{
			int t;
			scanf("%d", &t);
			scanf("%d%d", &school[t].b, &school[t].c);
		}
		for(int i = 0;i < Tea;i++)
		{
			int t, n;
			scanf("%d%d", &t, &n);
			if(n >= Min_ && school[t].num < 3)
				school[t].a = 1;
		}
		int ans = 0;
		for(int i = 1;i <= Sch;i++)
		{
			//school[i].pr();
			ans += school[i].a + school[i].b + school[i].c;
		}
		printf("Case %d: %d\n", ++o, ans);
	}
	return 0;
}