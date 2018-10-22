#include <stdio.h>
#include <string.h>
int main()
{
	char command[12],code[105];
	while(scanf("%s",command)&&strcmp(command,"START")==0)
	{
		getchar();
		gets(code);
		gets(command);
		int l = strlen(code);
		for(int i = 0;i < l;i++)
		{
			if(code[i]>='A'&&code[i]<='E')
				code[i]+=21;
			else if(code[i]>='F'&&code[i]<='Z')
				code[i]-=5;
		}
		printf("%s\n", code);
	}
}