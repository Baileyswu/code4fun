#include <stdio.h>
#include <string.h>
double mp[35][35];
char chart[35][100];
int main()
{
	int n, m, i, j, o = 0;
	char one[100], two[100];
	double rate;
	while(scanf("%d", &n), n)
	{
		memset(mp, 0, sizeof(mp));
		memset(chart, 0, sizeof(chart));
		for(i = 0;i < n;i++)
			scanf("%s", chart[i]);
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%lf%s", one, &rate, two);
			for(i = 0;i < n;i++)
				if(!strcmp(one, chart[i]))
					break;
			for(j = 0;j < n;j++)
				if(!strcmp(two, chart[j]))
					break;
			mp[i][j] = rate;
		}
		for(int k = 0;k < n;k++)
			for(i = 0;i < n;i++)
				for(j = 0;j < n;j++)
					if(mp[i][k] * mp[k][j] > mp[i][j])
						mp[i][j] = mp[i][k] * mp[k][j];
		int v = 0;
		for(int i = 0;i < n;i++)
			if(mp[i][i] > 1.0)
			{
				v = 1;
				break;
			}
		if(v)
			printf("Case %d: Yes\n", ++o);
		else
			printf("Case %d: No\n", ++o);
	}
	return 0;
}