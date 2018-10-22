#include <stdio.h>
#include <string.h>
int dig[800], ans[10];
int main()
{
	int n, i, k;
	while(scanf("%d", &n), n)
	{
		memset(dig, 0, sizeof(dig));
		memset(ans, 0, sizeof(ans));
		dig[0] = 1;
		int p = 0;
		for(k = 1;k <= n;k++)
		{
			for(i = 0;i <= p;i++)
				dig[i] *= k;
			for(i = 0;i <= p;i++)
				if(dig[i] > 9)
				{
					dig[i+1]+=dig[i]/10;
					dig[i]%=10;
				}
			if(dig[p+1])
			{
				p = p+1;
				for(i = p;i < 799;i++)
				{
					if(dig[i] > 9)
					{
						dig[i+1]+=dig[i]/10;
						dig[i]%=10;
					}
					else
					{
						p = i;
						break;
					}
				}
			}
		}
		for(i = 0;i <= p;i++)
			ans[dig[i]]++;
		printf("%d! --\n", n);
		for(i = 0;i < 10;i++)
			printf("   (%d)%5d%c", i, ans[i], " \n"[i==4||i==9]);
	}
	return 0;
}
