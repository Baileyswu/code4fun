#include <stdio.h>
#include <string.h>
int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		char com[300];
		gets(com);
		int len = strlen(com), i, op;
		int left = -1, a, mid, right, v;
		while(1)
		{
			v = 0;
			for(i = left+1; i < len;i++)
			{
				if(com[i] == '(')
				{
					left = i;
					v = 1;
					break;
				}
			}
			if(!v)
				break;
			a = 1, mid = 0;
			for(i = left+1;i < len;i++)
			{
				if(com[i] == '(')
					a++;
				else if(com[i] == ')')
				{
					a--;
					if(!a)
					{
						right = i;
						break;
					}
				}
				else if(com[i] != ' ')
					mid++;
			}
			op = 1;
			for(i = left;i >= 0;i--)
			{
				if(com[i] == '+')
				{
					op = 1;
					break;
				}
				else if(com[i] == '-')
				{
					op = 0;
					break;
				}
			}
			if(op || mid<=1)
				com[left] = ' ', com[right] = ' ';
		}
		char ans[300];
		int j = 0;
		memset(ans, '\0', sizeof(ans));
		for(i = 0;i < len;i++)
		{
			if(com[i] != ' ')
				ans[j++] = com[i];
		}
		ans[j] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}