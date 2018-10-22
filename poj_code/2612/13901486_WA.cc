#include <stdio.h>
#include <string.h>
int mp[15][15], dp[16] = {0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
char set[15][15];
int main()
{
	int t;
	while(~scanf("%d", &t))
	{
		memset(mp, 0, sizeof(mp));
		for(int i = 0;i < t;i++)
		{
			scanf("%s", set[i]);
			for(int j = 0;j < t;j++)
				if(set[i][j] == '*')
				{
					for(int m = 0;m < 8;m++)
					{
						int x = i+dp[2*m], y = j+dp[2*m+1];
						if(x < 0||x >= t||y < 0||y >= t)
							continue;
						mp[x][y]++;
					}
				}
		}
		for(int i = 0;i < t;i++)
		{
			scanf("%s", set[i]);
			for(int j = 0;j < t;j++)
				if(set[i][j] == 'x')
					set[i][j] = mp[i][j]+'0';
			printf("%s\n", set[i]);
		}
	}
	return 0;
}