#include <stdio.h>
#include <string.h>
int main()
{
	char str[90];
	int let[26][26];
	while(~scanf("%s", str))
	{
		if(strcmp(str, "*") == 0)
			break;
		int len = strlen(str), v = 0;
		for(int i = 0;i < len-1;i++)
		{
			memset(let, 0, sizeof(let));
			for(int j = 0;j < len-1-i;j++)
			{
				if(let[str[j]-'A'][str[j+i+1]-'A'])
				{
					v = 1;
					printf("%s is NOT surprising.\n", str);
					break;
				}
				let[str[j]-'A'][str[j+i+1]-'A'] = 1;
			}
			if(v)
				break;
		}
		if(!v)
			printf("%s is surprising.\n", str);
	}
	return 0;
}