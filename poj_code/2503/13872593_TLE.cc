#include <stdio.h>
#include <string.h>
char dit[100010][2][15];
int main()
{
	char com[50];
	int p = 0;
	while(gets(com))
	{
		if(com[0]=='\0')
			break;
		sscanf(com, "%s%s", dit[p][0], dit[p][1]);
		p++;
	}
	while(gets(com))
	{
		int v = 0;
		for(int i = 0;i < p;i++)
		{
			if(strcmp(com, dit[i][1])==0)
			{
				printf("%s\n", dit[i][0]);
				v = 1;
				break;
			}
		}
		if(!v)
			printf("eh\n");
	}
	return 0;
}