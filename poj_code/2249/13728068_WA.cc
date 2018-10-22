#include <stdio.h>
#include <string.h>
#define D 9
#define N 100
int dig[N];

int main()
{
	int n, k;
	while(scanf("%d%d", &n, &k), n)
	{
		if(k > n/2)
			k = n - k;
		if(!k)
		{
			printf("1\n");
			continue;
		}
		int p = 0, i;
		memset(dig, 0, sizeof(dig));
		dig[0] = n-k+1;
		for(int m = n-k+2;m <= n;m++)
		{
			for(i = 0;i <= p;i++)
				dig[i] *= m;
			for(i = 0;i <= p;i++)
			{
				if(dig[i] > 9)
				{
					dig[i+1] += dig[i]/10;
					dig[i] %= 10;
				}
			}
			if(dig[p+1])
				p++;
			for(i = p;i < N;i++)
			{
				if(dig[i] < 10)
				{
					p = i;
					break;
				}
				dig[i+1] += dig[i]/10;
				dig[i] %= 10;
			}
		}
		for(int m = k;m > 1;m--)
		{
			for(i = p;i > 0;i--)
			{
				if(dig[i] < m)
				{
					dig[i-1] += dig[i]*10;
					dig[i] = 0;
					continue;
				}
				dig[i-1] += dig[i]%m*10;
				dig[i] /= m;
			}
			dig[0] /= m;
			for(i = p;i >= 0;i--)
				if(dig[i])
				{
					p = i;
					break;
				}
		}
		for(i = p;i >= 0;i--)
			printf("%d", dig[i]);
		printf("\n");
	}
	return 0;
}