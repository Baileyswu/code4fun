#include <stdio.h>
#include <string.h>
int main()
{
	int n, flag[100];
	char str[100];
	while(scanf("%d", &n), n)
	{
		if(!n)
			break;
		scanf("%s", str);
		int len = strlen(str), bed = 0, ans = 0;
		memset(flag, 0, sizeof(flag));
		for(int i = 0;i < len;i++)
		{
			if(flag[str[i]-'A'] == 1)
			{
				flag[str[i]-'A'] = 0;
				bed--;
			}
			else if(!flag[str[i]-'A'] && bed < n)
			{
				flag[str[i]-'A'] = 1;
				bed++;
				ans++;
			}
			else if(!flag[str[i]-'A'] && bed == n)
				flag[str[i]-'A'] = -1;
			else if(flag[str[i]-'A']==-1)
				flag[str[i]-'A'] = 0;
		}
		if(ans == len/2)
			printf("All customers tanned successfully.\n");
		else
			printf("%d customer(s) walked away.\n", len/2-ans);

	}
}