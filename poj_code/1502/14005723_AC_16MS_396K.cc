#include <stdio.h>
#include <string.h>
int mp[105][105], n;
#define Max 1000000000
int floyd()
{
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(mp[i][k] + mp[k][j] < mp[i][j])
					mp[i][j] = mp[i][k]+mp[k][j];
	int ans = 0;
	for(int j = 2;j <= n;j++)
		if(ans < mp[1][j])
			ans = mp[1][j];
	printf("%d\n", ans);
	return 0;
}
int main()
{
	while(~scanf("%d", &n))
	{
		char temp[20];
		int dis;
		memset(mp, 0, sizeof(mp));
		for(int i = 1;i <= n;i++)
		{
			mp[i][i] = 0;
			for(int j = 1;j < i;j++)
			{
				scanf("%s", temp);
				if(temp[0] == 'x')
					dis = Max;
				else
					sscanf(temp, "%d", &dis);
				mp[i][j] = mp[j][i] = dis;
			}
		}
		floyd();
	}
	return 0;
}