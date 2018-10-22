#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int cmp(char x, char y)
{
	return x < y;
}
int main()
{
	int num[100];
	char str[100], la[100], one[100];
	while(~scanf("%s", str))
	{
		int len = strlen(str), v = 0;
		strcpy(one, str);
		sort(one, one+len, cmp);
		for(int i = 1;i <= len;i++)
		{
			for(int j = 0;j < len;j++)
				num[j] = (str[j]-'0')*i;
			for(int j = len-1;j >= 0;j--)
				if(num[j] > 9)
				{
					if(j)
						num[j-1] += num[j]/10;
					num[j] %= 10;
				}
			for(int j = 0;j < len;j++)
				la[j] = '0' + num[j];
			la[len] = '\0';
			//printf("%s\n", la);
			sort(la, la+len, cmp);
			if(strcmp(one, la))
			{
				v = 1;
				printf("%s is not cyclic\n", str);
				break;
			}
		}
		if(!v)
			printf("%s is cyclic\n", str);
	}
	return 0;
}