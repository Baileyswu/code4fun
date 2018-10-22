#include <cstdio>
#include <cstring>
char str[105][105], mp[105][105];

int paint(int x, int y, int r, int c)
{
	for(int i = x;i < x+r;i++)
		for(int j = y;j < y+c;j++)
			mp[i][j] = '1' - mp[i][j] + '0';
}
int pr(int n, int m)
{
	printf("--------\n");
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			printf("%c%c", mp[i][j], " \n"[j==m-1]);
}
int main()
{
	int n, m, r, c;
	while(scanf("%d%d%d%d", &n, &m, &r, &c))
	{
		if(!n && !m && !r && !c)
			break;
		for(int i = 0;i < n;i++)
			scanf("%s", str[i]);
		memset(mp, '0', sizeof(mp));
		int v = 0, ans = 0;
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				if(str[i][j] == mp[i][j])
					continue;
				if(i+r>n || j+c>m)
				{
					v = 1;
					break;
				}
				paint(i, j, r, c);
				ans++;
				//pr(n, m);
			}
			if(v)
				break;
		}
		if(v)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}