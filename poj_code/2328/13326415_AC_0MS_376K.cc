#include <stdio.h>
#include <string.h>
bool num[11];
int clear()
{
	for(int i = 1;i < 11;i++)
		num[i] = true;
	return 0;
}
int main()
{
	int x, i;
	char command[10];
	clear();
	while(scanf("%d", &x) && x)
	{
		getchar();
		gets(command);
		if(strcmp(command, "too high") == 0)
			for(i = x;i < 11;i++)
				num[i] = false;
		else if(strcmp(command, "too low") == 0)
			for(i = 1;i <= x;i++)
				num[i] = false;
		else if(strcmp(command, "right on") == 0)
		{
			if(num[x])
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			clear();
		}
	}
	return 0;
}