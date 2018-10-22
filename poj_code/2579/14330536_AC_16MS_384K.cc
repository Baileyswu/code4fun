#include <stdio.h>
#include <string.h>
int main()
{
	char str[20], mp[12][12], ans[12][12];
	int R, C;
	while(scanf("%s", str))
	{
		if(strcmp(str, "ENDOFINPUT") == 0)
			break;
		scanf("%d%d", &R, &C);
		for(int i = 0;i < R;i++)
			scanf("%s", mp[i]);
		scanf("%s", str);
		for(int i = 0;i < R-1;i++)
		{
			for(int j = 0;j < C-1;j++)
			{
				ans[i][j] = '0'+(mp[i][j]+mp[i+1][j+1]
						+mp[i][j+1]+mp[i+1][j]-4*'0')/4;
			}
			ans[i][C-1] = '\0';
		}
		for(int i = 0;i < R-1;i++)
			printf("%s\n", ans[i]);
	}
	return 0;
}