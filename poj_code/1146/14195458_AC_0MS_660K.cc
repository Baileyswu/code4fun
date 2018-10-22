#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char str[1000];
int swap(int x, int y)
{
	char t = str[x];
	str[x] = str[y];
	str[y] = t;
}
bool cmp(char a, char b)
{
	return a < b;
}
int main()
{
	while(scanf("%s", str))
	{
		if(strcmp(str, "#") == 0)
			break;
		int len = strlen(str), q = -2;
		for(int i = len-1;i > 0;i--)
		{
			if(str[i] > str[i-1])
			{
				q = i-1;
				break;
			}
		}
		if(q == -2)
		{
			printf("No Successor\n");
			continue;
		}
		for(int i = len-1;i > q;i--)
		{
			if(str[i] > str[q])
			{
				swap(i, q);
				break;
			}
		}
		sort(str+q+1, str+len, cmp);
		printf("%s\n", str);
	}
	return 0;
}