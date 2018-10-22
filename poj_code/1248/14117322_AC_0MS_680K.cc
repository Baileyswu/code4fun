#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int x, int y)
{
	return x > y;
}
int main()
{
	int n, num[100], flag[100];
	char str[100];
	while(scanf("%d%s", &n, str))
	{
		if(strcmp(str, "END") == 0)
			break;
		int len = strlen(str);
		memset(flag, 0, sizeof(flag));
		for(int i = 0;i < len;i++)
			num[i] = str[i] - 'A' + 1;
		sort(num, num+len, cmp);
		int ans = 0;
		for(int v = 0;v < len;v++)
		{
			flag[v] = 1;
			for(int w = 0;w < len;w++)
			{
				if(flag[w])
					continue;
				flag[w] = 1;
				for(int x = 0;x < len;x++)
				{
					if(flag[x])
						continue;
					flag[x] = 1;
					for(int y = 0;y < len;y++)
					{
						if(flag[y])
							continue;
						flag[y] = 1;
						for(int z = 0;z < len;z++)
						{
							if(flag[z])
								continue;
							flag[z] = 1;
							if(num[v]-num[w]*num[w]+num[x]*num[x]*num[x]-num[y]*num[y]*num[y]*num[y]+num[z]*num[z]*num[z]*num[z]*num[z] == n)
							{
								printf("%c%c%c%c%c\n", num[v]-1+'A',num[w]-1+'A',num[x]-1+'A',num[y]-1+'A',num[z]-1+'A');
								ans = 1;
								goto p;
							}
							flag[z] = 0;
						}
						flag[y] = 0;
					}
					flag[x] = 0;
				}
				flag[w] = 0;
			}
			flag[v] = 0;
		}
		p:;
		if(!ans)
			printf("no solution\n");
	}
	return 0;
}