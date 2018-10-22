#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char str[3][105];
	int f[105];
	while(~scanf("%s%s", str[1], str[2]))
	{
		int p = 0;
		int ans = 3000;
		for(int s = 0;s < 2;s++)
		{
			//printf("str1  %s   str2  %s\n", str[1], str[2]);
			int la = strlen(str[1]), lb = strlen(str[2]);
			for(int i = 0;i < la;i++)
				str[0][i] = '1';
			for(int i = la;i < la+lb;i++)
				str[0][i] = str[2][i-la];
			for(int i = 0;i < la;i++)
				if(str[1][i] == '2')
					f[p++] = i;
			for(int i = la+lb-1;i >= 0;i--)
				if(str[0][i] == '1')
				{
					int v = 0;
					for(int j = 0;j < p;j++)
					{
						if(f[j]-f[0]+i >= lb+la)
							break;
						if(str[0][f[j]-f[0]+i] != '1')
						{
							v = 1;
							break;
						}
					}
					if(!v)
					{
						v = max(f[0], i-la) + max(la-f[0], la+lb-i);
						if(ans > v)
							ans = v;
						//printf("--%d %d %d\n", i, v, ans);
					}
				}
			char temp[105];
			strcpy(temp, str[1]);strcpy(str[1], str[2]);
			strcpy(str[2], temp);
			//printf("temp%s\n", temp);
		}
		printf("%d\n", ans);
	}
	return 0;
}