#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char str[15][15];
int n, m;
int solve(char type, int num)
{
	int i, j, v = 0;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < m;j++)
			if(str[i][j] == type)
			{
				v = 1;
				break;
			}
		if(v)
			break;
	}
	int r = 0;
	//printf("(%d %d)\n", i+1, j+1);
	switch(type)
	{
		case '-':
		for(;j < m && v;j++)
			if(str[i][j] == type)
				r++;
			else
				break;
		break;

		case 92:
		for(;i < n && v && j < m;i++, j++)
			if(str[i][j] == type)
				r++;
			else
				break;
		break;

		case '|':
		for(;j < m && v;j++)
			if(str[i][j] == type)
				r++;
			else
				break;
		break;

		case '/':
		for(;i >= 0 && v && j >= 0;i--, j--)
			if(str[i][j] == type)
				r++;
			else
				break;
		break;
	}
	//printf("num:%d  r:%d\n", num, r);
	if(r == num)
		printf("CORRECT\n");
	else
		printf("INCORRECT\n");
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		int ans = 0, num = 1;
		char type = '.';
		for(int i = 0;i < n;i++)
		{
			scanf("%s", str[i]);
			for(int j = 0;j < m;j++)
			{
				if(str[i][j] == '.')
					continue;
				if(type == '.')
					type = str[i][j];
				else
				{
					if(type != str[i][j])
					{
						ans = 1;
						break;
					}
					else
						num++;
				}
			}
		}
		if(type == '.' || ans)
		{
			printf("INCORRECT\n");
			continue;
		}
		//printf("-------%c %d\n", type, num);
		solve(type, num);
	}
	return 0;
}