#include <stdio.h>
#include <string.h>
int la, lb, lc, t, flag[410];
char a[205], b[205], c[410];
int dfs(int x, int y)
{
	if(x == la)
	{
		int p = 0;
		for(int i = 0;i < lc;i++)
		{
			if(!flag[i] && p < lb)
			{
				if(c[i] == b[p])
					flag[i] = -1, p++;
				else
				{
					for(int i = 0;i < lc;i++)
						if(flag[i] < 0)
							flag[i] = 0;
					return 0;
				}
			}
			if(p == lb)
				return 1;
		}
	}
	for(int i = y;i < lc;i++)
	{
		if(!flag[i] && c[i] == a[x])
		{
			flag[i] = 1;
			if(dfs(x+1, i+1))
				return 1;
			flag[i] = 0;
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &t);
	for(int p = 0;p < t;p++)
	{
		scanf("%s%s%s", a, b, c);
		la = strlen(a), lb = strlen(b), lc = strlen(c);
		if(la + lb != lc)
		{
			printf("Data set %d: no\n", p+1);
			continue;
		}
		memset(flag, 0, sizeof(flag));
		if(dfs(0, 0))
			printf("Data set %d: yes\n", p+1);
		else
			printf("Data set %d: no\n", p+1);
	}
	return 0;
}