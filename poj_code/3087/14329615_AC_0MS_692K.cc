#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int n, a;
	char str[3][400], end[400];
	while(~scanf("%d", &n))
	{
		for(int m = 1;m <= n;m++)
		{
			int v = 0;
			scanf("%d%s%s%s", &a, str[1], str[2], end);
			for(int p = 0;p < 3*a;p++)
			{
				for(int i = 0;i < a;i++)
				{
					str[0][2*i] = str[2][i];
					str[0][2*i+1] = str[1][i];
				}
				str[0][2*a] = '\0';
				if(strcmp(str[0], end) == 0)
				{
					printf("%d %d\n", m, p+1);
					v = 1;
					break;
				}
				strcpy(str[1], str[0]);
				for(int i = 0;i < a;i++)
					str[2][i] = str[0][i+a];
				//printf("%d %s\n", p+1, str[0]);
			}
			if(!v)
				printf("%d -1\n", m);
		}
	}
	return 0;
}