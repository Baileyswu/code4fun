#include <stdio.h>
#include <string.h>
int mp[105][105], n;
int main()
{
	int m;
	while(~scanf("%d%d", &n, &m))
	{
		memset(mp, 0, sizeof(mp));
		int win, lose;
		while(m--)
		{
			scanf("%d%d", &win, &lose);
			mp[win][lose] = 1;
		}
		for(int k = 1;k <= n;k++)
			for(int i = 1;i <= n;i++)
				for(int j = 1;j <= n;j++)
					if(mp[i][k] && mp[k][j])
						mp[i][j] = 1;
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int temp = 0;
			for(int j = 1;j <= n;j++)
				temp += mp[i][j]+mp[j][i];
			if(temp == n-1)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}