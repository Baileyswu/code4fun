#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	char name[15][26], temp[26];
	while(scanf("%d", &n) && n)
	{
		int i = 0;
		while(n--)
		{
			i++;
			scanf("%s", temp);
			if(i % 2)
				printf("%s\n", temp);
			else
				strcpy(name[i], temp);
		}
		while(i >= 2)
		{
			if(i % 2 == 0)
				printf("%s\n", name[i]);
			i--;
		}
	}
	return 0;
}