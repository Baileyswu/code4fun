#include <stdio.h>
#include <string.h>
int main()
{
	int c;
	bool flag[11];
	scanf("%d", &c);
	while(c--)
	{
		memset(flag, 0, sizeof(flag));
		char left[3][15], right[3][15], com[3][15];
		int ll, rr;
		for(int k = 0;k < 3;k++)
		{
			scanf("%s%s%s", left[k], right[k], com[k]);
			ll = strlen(left[k]), rr = strlen(right[k]);
			if(strcmp(com[k], "even") == 0)
			{
				for(int i = 0;i < ll;i++)
					flag[left[k][i]-'A'] = 1;
				for(int i = 0;i < rr;i++)
					flag[right[k][i]-'A'] = 1;
			}
		}
		int v = 0, ans;
		for(int k = 0;k < 3;k++)
		{
			ll = strlen(left[k]), rr = strlen(right[k]);
			if(strcmp(com[k], "up") == 0)
			{
				for(int i = 0;i < ll;i++)
					if(!flag[left[k][i]-'A'])
					{
						v = 1;
						printf("%c is the counterfeit coin and it is heavy.\n", left[k][i]);
						break;
					}
				if(v)
					break;
				for(int i = 0;i < rr;i++)
					if(!flag[right[k][i]-'A'])
					{
						v = 1;
						printf("%c is the counterfeit coin and it is light.\n", right[k][i]);
						break;
					}
				if(v)
					break;
			}
			else if(strcmp(com[k], "down") == 0)
			{
				for(int i = 0;i < ll;i++)
					if(!flag[left[k][i]-'A'])
					{
						v = 1;
						printf("%c is the counterfeit coin and it is light.\n", left[k][i]);
						break;
					}
				if(v)
					break;
				for(int i = 0;i < rr;i++)
					if(!flag[right[k][i]-'A'])
					{
						v = 1;
						printf("%c is the counterfeit coin and it is heavy.\n", right[k][i]);
						break;
					}
				if(v)
					break;
			}	
		}
	}
}