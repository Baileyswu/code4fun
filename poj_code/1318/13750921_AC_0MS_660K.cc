#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int cmp(char a, char b)
{
	return a < b;
}
int main()
{
	char com[10], dict[110][10], alp[110][10];
	int i = 0, j;
	while(scanf("%s", com))
	{
		if(!strcmp("XXXXXX", com))
			break;
		strcpy(dict[i], com);
		i++;
	}
	int size = i;
	for(i = 0;i < size;i++)
		for(j = i;j < size;j++)
		{
			if(strcmp(dict[i], dict[j]) > 0)
			{
				strcpy(com, dict[j]);
				strcpy(dict[j], dict[i]);
				strcpy(dict[i], com);
			}
		}
	for(i = 0;i < size;i++)
	{
		strcpy(com, dict[i]);
		int len = strlen(com);
		sort(com, com+len, cmp);
		strcpy(alp[i], com);
	}
	while(scanf("%s", com))
	{
		if(!strcmp("XXXXXX", com))
			break;
		int len = strlen(com), w = 0;
		sort(com, com+len, cmp);
		for(i = 0;i < size;i++)
			if(!strcmp(com, alp[i]))
			{
				printf("%s\n", dict[i]);
				w = 1;
			}
		if(!w)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}