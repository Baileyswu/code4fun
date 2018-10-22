#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
bool flag[8][8];
queue <int> line;
int dp[8][2] = {1,2,2,1,1,-2,2,-1,-1,-2,-2,-1,-1,2,-2,1};
int mp[8][8];
int pr()
{
	for(int i = 0;i < 8;i++)
	{
		for(int j = 0;j < 8;j++)
			printf("%d ", mp[i][j]);
		printf("\n");
	}
}
int main()
{
	char str1[3], str2[3];
	while(~scanf("%s%s", str1, str2))
	{
		int a = str1[0]-'a', b = str1[1]-'1', c = str2[0]-'a', d = str2[1]-'1';
		memset(flag, 0, sizeof(flag));
		memset(mp, 0, sizeof(mp));
		line.push(a*8+b);
		mp[a][b] = 1;
		int temp, v = 0;
		while(1)
		{
			temp = line.front();
			line.pop();
			for(int i = 0;i < 8;i++)
			{
				int n = temp/8+dp[i][0], m = temp%8+dp[i][1];
				if(mp[n][m]||n<0||n>7||m<0||m>7)
					continue;
				mp[n][m] = 1+mp[temp/8][temp%8];
				if(n==c&&m==d)
				{
					v = 1;
					break;
				}
				line.push(n*8+m);
			}
			if(v||mp[c][d])
				break;
		}
		printf("To get from %s to %s takes %d knight moves.\n", str1, str2, mp[c][d]-1);
		while(!line.empty())
			line.pop();
	}
	return 0;
}
