#include <stdio.h>
#include <string.h>
int main()
{
	char in[1000], out[2000];
	while(~scanf("%s", in))
	{
		int len = strlen(in), i, p, v = 0, flag = 0;
		if(!(in[0] >= 'a' && in[0] <= 'z') || in[len-1] == '_')
		{
			printf("Error!\n");
			continue;
		}
		for(i = 0;i < len;i++)
			if(in[i] == '_')
			{
				if(in[i-1] == '_' || v == 2)
				{
					printf("Error!\n");
					flag = 1;
					break;
				}
				v = 1;
			}
			else if(in[i] >= 'A' && in[i] <= 'Z')
			{
				if(v == 1)
				{
					printf("Error!\n");
					flag = 1;
					break;
				}
				v = 2;
			}
		if(flag)
			continue;
		if(v == 1)
		{
			for(i = 0, p = 0;i < len;i++, p++)
			{
				if(in[i] == '_')
					out[p] = in[++i]-32;
				else
					out[p] = in[i];
			}
			out[p] = '\0';
		}
		else
		{
			for(i = 0, p = 0;i < len;i++, p++)
			{
				if(in[i] >= 'A' && in[i] <= 'Z')
				{
					out[p] = '_';
					out[++p] = in[i]+32;
				}
				else
					out[p] = in[i];
			}
			out[p] = '\0';
		}
		printf("%s\n", out);
	}
	return 0;
}