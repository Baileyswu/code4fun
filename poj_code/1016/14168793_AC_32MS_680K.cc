#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int flag[10];
char temp[1000];
int list[1000];
int gao(char a[])
{
	int len = strlen(a);
	memset(flag, 0, sizeof(flag));
	for(int i = 0;i < len;i++)
		flag[a[i]-'0']++;
	int p = 0;
	for(int i = 0;i < 10;i++)
	{
		if(flag[i])
		{
			int q = 0;
			while(flag[i])
			{
				list[q++] = flag[i]%10;
				flag[i] /= 10;
			}
			while(q)
				temp[p++] = list[--q]+'0';
			temp[p++] = i + '0';
		}
	}
	temp[p++] = '\0';
}
int main()
{
	char str[1000], a[1000], b[1000], com[20][1000];
	while(scanf("%s", str))
	{
		memset(com, '\0', sizeof(com));
		if(strcmp(str, "-1") == 0)
			break;
		int len = strlen(str);
		gao(str);
		if(strcmp(str, temp) == 0)
		{
			printf("%s is self-inventorying\n", str);
			continue;
		}
		int cou = 1, v = 0;
		strcpy(b, temp);
		strcpy(com[cou], b);
		//printf("temp1:%s\n", temp);
		while(cou++ < 15)
		{
			strcpy(a, b);
			gao(a);
			//printf("temp:%s\n", temp);
			if(strcmp(a, temp) == 0)
			{
				printf("%s is self-inventorying after %d steps \n", str, cou-1);
				break;
			}
			strcpy(b, temp);
			for(int i = 0;i < cou;i++)
				if(strcmp(b, com[i]) == 0)
				{
					printf("%s enters an inventory loop of length %d\n", str, cou-i);
					v = 1;
					break;
				}
			if(v)
				break;
			strcpy(com[cou], b);
		}
		if(cou >= 15 && !v)
		{
			printf("%s can not be classified after 15 iterations\n", str);
			continue;
		}			
	}
}