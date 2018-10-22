#include <stdio.h>
#include <string.h>
int main()
{
	char com[20];
	while(~scanf("%s", com))
	{
		int sum = 0, p, i;
		for(int i = 0;i < 10;i++)
		{
			if(com[i] == 'X')
				com[i] = 10+'0';
			if(com[i] != '?')
				sum += (com[i]-'0')*(10-i);
			if(com[i] == '?')
				p = i;
		}
		int v = 0;
		for(i = 0;i < 11;i++)
			if((sum + p*i)%11==0)
			{
				v = 1;
				break;
			}
		if(!v)
		{
			printf("-1\n");
			continue;
		}
		if(i < 10)
			printf("%d\n", i);
		else
			printf("X\n");
	}
	return 0;
}