#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define Max 1000000000
int flag[1100];
int set(int n)
{
	for(int i = 0;i <= n;i++)
		flag[i] = Max;
}
int main()
{
	int n, k, m, one[555], two[555];
	while(~scanf("%d%d", &n, &k))
	{
		set(n);
		for(int s = 1;s <= k;s++)
		{
			scanf("%d", &m);
			for(int i = 0;i < m;i++)
				scanf("%d", &one[i]);
			for(int i = 0;i < m;i++)
				scanf("%d", &two[i]);
			char com[2];
			scanf("%s", com);
			if(com[0] == '=')
			{
				for(int i = 0;i < m;i++)
					flag[two[i]] = flag[one[i]] = 0;
			}
			else if(com[0] == '<')
			{
				for(int i = 0;i < m;i++)
				{
					if(flag[one[i]])
						flag[one[i]] = 0-s;
					if(flag[two[i]])
						flag[two[i]] = s;
				}
			}
			else if(com[0] == '>')
			{
				for(int i = 0;i < m;i++)
				{
					if(flag[one[i]])
						flag[one[i]] = s;
					if(two[i])
						flag[two[i]] = 0-s;
				}
			}
		}
		int v = 0, key;
		for(int i = 1;i < n;i++)
		{
			if(flag[i])
				key = i, v++;
		}
		if(v > 1)
			printf("0\n");
		else
			printf("%d\n", key);
				
	}
	return 0;
}