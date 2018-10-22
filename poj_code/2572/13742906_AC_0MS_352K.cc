#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	int a, b, c;
	while(~scanf("%s", s))
	{
		int len = strlen(s);
		char m[100];
		for(int i = 0;i < len;i++)
			m[i] = s[len-1-i];
		m[len] = '\0';
		sscanf(m, "%d=%d+%d", &a, &b, &c);
		if(c+b==a)
			printf("True\n");
		else
			printf("False\n");
		if(!a&&!b&&!c)
			break;
	}	
	return 0;
}
			