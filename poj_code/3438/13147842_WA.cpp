#include <stdio.h>
#include <string.h>
int main()
{
	int t, k;
	char number[1000];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", number);
		int len = strlen(number);
		k = 1;
		for(int i = 1;i < len;i++)
		{
			if(number[i] == number[i - 1])
				k++;
			else
			{
				printf("%d%c", k, number[i - 1]);
				k = 1;
			}
		}
		printf("%d%c\n", k, number[len - 1]);
	}
	return 0;
}