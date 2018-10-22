#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int fact[8] = {9,3,7,9,3,7,9};
int main()
{
	int t, p = 0;
	scanf("%d", &t);
	while(t--)
	{
		printf("Scenario #%d:\n", ++p);
		int i, num[10];
		char id[10];
		scanf("%s", id);
		int len = strlen(id), s = 0, flag;
		for(i = 0;i < len;i++)
		{
			if(id[i] == '?')
			{
				flag = i;
				continue;
			}
			s += (id[i] - '0')*fact[len-1-i];
		}
		s %= 10;
		for(i = 0;i < 10;i++)
			if((i*fact[len-1-flag]+s)%10 == 0)
				break;
		id[flag] = i+'0';
		printf("%s\n\n", id);
	}
	return 0;
}
