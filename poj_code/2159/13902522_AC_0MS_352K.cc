#include <stdio.h>
#include <string.h>
int main()
{
	char a[105], b[105];
	int f[2][26];
	while(~scanf("%s%s", &a, &b))
	{
		int la = strlen(a), lb = strlen(b);
		if(la != lb)
		{
			printf("NO\n");
			continue;
		}
		memset(f, 0, sizeof(f));
		for(int i = 0;i < la;i++)
			f[0][a[i]-'A']++, f[1][b[i]-'A']++;
		int v = 0, w = 0;
		for(int i = 0;i < 26;i++)
		{
			v = 0;
			for(int j = 0;j < 26;j++)
			{
				if(f[0][i] == f[1][j])
				{
					f[1][j] = -1, v = 1;
					break;
				}
			}
			if(!v)
			{
				printf("NO\n");
				w = 1;
				break;
			}
		}
		if(!w)
			printf("YES\n");
	}
	return 0;
}