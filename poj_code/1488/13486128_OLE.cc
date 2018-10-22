#include <stdio.h>
#include <string.h>
int main()
{
	char c;
	int count = 1;
	while(c = getchar())
	{
		if(c == '"')
		{
			if(count)
				printf("``");
			else
				printf("''");
			count = 1 - count;
		}
		else
			printf("%c", c);
	}
	return 0;
}