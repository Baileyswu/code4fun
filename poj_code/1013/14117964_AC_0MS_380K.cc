#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int t, flag[20];
	scanf("%d", &t);
	char left[100], right[100], com[10];
	while(t--)
	{
		memset(flag, 0, sizeof(flag));
		for(int i = 0;i < 3;i++)
		{
			scanf("%s%s%s", left, right, com);
			if(strcmp(com, "even")==0)
			{
				for(int i = 0;i < strlen(left);i++)
					flag[left[i]-'A'] = 100;
				for(int i = 0;i < strlen(right);i++)
					flag[right[i]-'A'] = 100;
			}
			else if(strcmp(com, "up")==0)
			{
				for(int i = 0;i < strlen(left);i++)
					if(flag[left[i]-'A'] != 100)
						flag[left[i]-'A']++;
				for(int i = 0;i < strlen(right);i++)
					if(flag[right[i]-'A'] != 100)
						flag[right[i]-'A']--;
			}
			else if(strcmp(com, "down")==0)
			{
				for(int i = 0;i < strlen(left);i++)
					if(flag[left[i]-'A'] != 100)
						flag[left[i]-'A']--;
				for(int i = 0;i < strlen(right);i++)
					if(flag[right[i]-'A'] != 100)
						flag[right[i]-'A']++;
			}
			//for(int i = 0;i < 12;i++)
			//	printf("%c%d%c", i+'A', flag[i], " \n"[i==11]);
		}
		int ans = 0, k = -1;
		for(int i = 0;i < 12;i++)
			if(flag[i] != 100 && ans < abs(flag[i]))
			{
				ans = abs(flag[i]);
				k = i;
			}
		if(flag[k] < 0)
			printf("%c is the counterfeit coin and it is light. \n", k+'A');
		else
			printf("%c is the counterfeit coin and it is heavy. \n", k+'A');
	}
	return 0;
}