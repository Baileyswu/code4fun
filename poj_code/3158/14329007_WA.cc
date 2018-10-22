#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char str1[105], str2[205], str3[105];
	int f[105];
	while(~scanf("%s%s", str1, str2))
	{
		int p = 0;
		int la = strlen(str1), lb = strlen(str2);
		for(int i = 0;i < la;i++)
			str3[i] = '1';
		for(int i = la;i < la+lb;i++)
			str3[i] = str2[i-la];
		for(int i = 0;i < la;i++)
			if(str1[i] == '2')
				f[p++] = i;
		int ans = la+lb;
		for(int i = la+lb-1;i >= 0;i--)
			if(str3[i] == '1')
			{
				int v = 0;
				for(int j = 0;j < p;j++)
				{
					if(f[j]-f[0]+i >= lb+la)
						break;
					if(str3[f[j]-f[0]+i] != '1')
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
		printf("%d\n\n", ans);
	}
	return 0;
}