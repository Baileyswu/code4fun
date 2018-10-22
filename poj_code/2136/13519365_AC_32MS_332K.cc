#include <stdio.h>
#include <string.h>
int main()
{
	bool mp[26][72*4];
	int al[26], i, j, k;
	char str[80];
	memset(al, 0, sizeof(al));
	memset(mp, 0, sizeof(mp));
	for(i = 0;i < 4;i++)
	{
		gets(str);
		int len = strlen(str);
		for(j = 0;j < len;j++)
			if(str[j] >= 'A' && str[j] <= 'Z')
				al[str[j] - 'A']++;
	}
	int ma = -1;
	for(j = 0;j < 26;j++)
		if(ma < al[j])
			ma = al[j];
	for(j = 0;j < 26;j++)
	{
		for(k = 0;k < ma - al[j];k++)
			mp[j][k] = 0;
		for(;k < ma;k++)
			mp[j][k] = 1;
	}
	for(k = 0;k < ma;k++)
	{
		for(j = 0;j < 26;j++)
		{
			if(j)
				printf(" ");
			if(mp[j][k])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	for(j = 0;j < 26;j++)
	{
		if(j)
			printf(" ");
		printf("%c", j + 'A');
	}
	printf("\n");
	return 0;
}