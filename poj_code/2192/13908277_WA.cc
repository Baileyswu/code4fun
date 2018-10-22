#include <stdio.h>
#include <string.h>
char a[205], b[205], c[410];
int la, lb, lc, ans[205][205], res[410], i, j, k;
int main()
{
	int t, v;
	scanf("%d", &t);
	for(int p = 1;p <= t;p++)
	{
		scanf("%s%s%s", a+1, b+1, c+1);
		la = strlen(a+1), lb = strlen(b+1), lc = strlen(c+1);
		memset(ans, 0, sizeof(ans));
		memset(res, 0, sizeof(res));
		ans[0][0] = res[0] = 1;
		for(k = 1;k <= la+lb;k++)
		{
			if(!res[k-1])
			{
				printf("Data set %d: no\n", p);
				break;
			}
			for(j = 0;j <= k;j++)
			{
				i = k-j;
				if(j > lb || i > la)
					continue;
				if(!j && ans[0][k-1] && a[k]==c[k])
					ans[0][k] = res[k] = 1;
				else if(!i && ans[k-1][0] && b[k]==c[k])
					ans[k][0] = res[k] = 1;
				else if((ans[j][i-1])&&a[i]==c[k]||(ans[j-1][i]&&b[j]==c[k]))
					ans[j][i] = res[k] = 1;
			}
		}
		if(res[la+lb])
			printf("Data set %d: yes\n", p);
	}
	return 0;
}