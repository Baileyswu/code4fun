#include <stdio.h>
#include <string.h>
char a[10][16];
int main()
{
	strcpy(a[0], " - | |   | | - ");
	strcpy(a[1], "     |     |   ");
	strcpy(a[2], " -   | - |   - ");
	strcpy(a[3], " -   | -   | - ");
	strcpy(a[4], "   | | -   |   ");
	strcpy(a[5], " - |   -   | - ");
	strcpy(a[6], " - |   - | | - ");
	strcpy(a[7], " -   |     |   ");
	strcpy(a[8], " - | | - | | - ");
	strcpy(a[9], " - | | -   | - ");
	int n, i;
	char number[10];
	while(scanf("%d%s", &n, &number) && n != 0)
	{
		int len =strlen(number);
		for(int j = 0;j < len;j++)
		{
			printf("%c", a[number[j]-'0'][3 * 0]);
			for(int k = 0;k < n;k++)
				printf("%c", a[number[j]-'0'][3 * 0 + 1]);
			printf("%c", a[number[j]-'0'][3 * 0 + 2]);
			if(j < len - 1)
				printf(" ");
		}
		printf("\n");
		for(i = 0;i < n;i++)
		{	for(int j = 0;j < len;j++)
			{
				printf("%c", a[number[j]-'0'][3 * 1]);
				for(int k = 0;k < n;k++)
					printf("%c", a[number[j]-'0'][3 * 1 + 1]);
				printf("%c", a[number[j]-'0'][3 * 1 + 2]);
				if(j < len - 1)
					printf(" ");
			}
			printf("\n");
		}
		for(int j = 0;j < len;j++)
		{
			printf("%c", a[number[j]-'0'][3 * 2]);
			for(int k = 0;k < n;k++)
				printf("%c", a[number[j]-'0'][3 * 2 + 1]);
			printf("%c", a[number[j]-'0'][3 * 2 + 2]);
			if(j < len - 1)
				printf(" ");
		}
		printf("\n");
		for(i = 0;i < n;i++)
		{	for(int j = 0;j < len;j++)
			{
				printf("%c", a[number[j]-'0'][3 * 3]);
				for(int k = 0;k < n;k++)
					printf("%c", a[number[j]-'0'][3 * 3 + 1]);
				printf("%c", a[number[j]-'0'][3 * 3 + 2]);
				if(j < len - 1)
					printf(" ");
			}
			printf("\n");
		}
		for(int j = 0;j < len;j++)
		{
			printf("%c", a[number[j]-'0'][3 * 4]);
			for(int k = 0;k < n;k++)
				printf("%c", a[number[j]-'0'][3 * 4 + 1]);
			printf("%c", a[number[j]-'0'][3 * 4 + 2]);
			if(j < len - 1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}