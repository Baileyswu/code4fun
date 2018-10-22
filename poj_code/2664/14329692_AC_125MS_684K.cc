#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int sel[105];
int cmp(int x, int y)
{
	return x < y;
}
int find(int num, int a, int b)
{
	//printf("a:%d b:%d\n", a, b);
	if(num < sel[a] || num > sel[b])
		return 0;
	if(a == b)
		return 1;
	if(num > sel[(a+b)/2])
		return find(num, (a+b)/2+1, b);
	return find(num, a, (a+b)/2);
}
int main()
{
	int k, s, num;
	while(scanf("%d", &k), k)
	{
		scanf("%d", &s);
		for(int i = 0;i < k;i++)
			scanf("%d", &sel[i]);
		sort(sel, sel+k, cmp);
		int c, m, ans = 0;
		while(s--)
		{
			scanf("%d%d", &c, &m);
			int p = 0;
			while(c--)
			{
				scanf("%d", &num);
				if(!ans)
					p += find(num, 0, k-1);
			}
			if(p < m)
				ans = 1;
		}
		if(ans)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}