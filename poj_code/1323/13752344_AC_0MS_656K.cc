#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
bool flag[1010];
int cmp(int x, int y)
{
	return x > y;
}
int main()
{
	int i, n, m, my[100], o = 1;
	while(scanf("%d%d", &n, &m), n)
	{
		memset(flag, 0, sizeof(flag));
		for(i = 0;i < m;i++)
		{
			scanf("%d", &my[i]);
			flag[my[i]] = 1;
		}
		sort(my, my+m, cmp);
		int p = n*m, ans = 0, inf = 1;
		for(i = 0;i < m;i++)
		{
			while(flag[p])p--;
			if(p > my[i])
			{
				p--;
				int x = n-2;
				while(x--)
					while(flag[inf++]);
			}
			else
			{
				ans++;
				int x = n-1;
				while(x--)
					while(flag[inf++]);
			}
		}
		printf("Case %d: %d\n", o++ ,ans);
	}
	return 0;
}