#include <stdio.h>
#include <string.h>
int s[3][100], p, co[3][100], q[3], ans[100];
int pr()
{
	for(int j = 0;j < 3;j++)
	{
		for(int i = p;i >= 0;i--)
			printf("%d ", s[j][i]);
		printf("\n");
	}
	printf("\n");
}
int set()
{
	for(int k = 3;k < 100;k++)
	{
		int t = k%3, i, m;
		for(i = 0;i <= p;i++)
		{
			for(m = 1;m < 3;m++)
				s[t][i] += s[(m+t)%3][i];
		}
		for(i = 0;i <= p;i++)
		{
			if(s[t][i] > 9)
			{
				s[t][i+1] += s[t][i]/10;
				s[t][i] %= 10;
			}
		}
		if(s[t][p+1])
			p++;
		for(i = p;i < 100;i++)
		{
			if(s[t][i] < 10)
			{
				p = i;
				break;
			}
			s[t][i+1] += s[t][i]/10;
			s[t][i] %= 10;
		}
	}

}
int main()
{
	for(int i = 0;i < 3;i++)
	{
		memset(s, 0, sizeof(s));
		s[i][0] = 1, p = 0;
		set();
		q[i] = p;
		for(int j = 0;j <= p;j++)
			co[i][j] = s[0][j];
	}
	/*for(int i = 0;i < 3;i++)
	{
		for(int j = q[i];j >= 0;j--)
			printf("%d ", co[i][j]);
		printf("\n");
	}*/
	int x[3];
	while(~scanf("%d%d%d", &x[0], &x[1], &x[2]))
	{
		if(!x[0] && !x[1] && !x[2])
		{
			printf("0\n");
			continue;
		}
		memset(ans, 0, sizeof(ans));
		for(int j = 0;j <= p;j++)
		{
			for(int i = 0;i < 3;i++)
				ans[j] += x[i]*co[i][j];
		}
		for(int j = 0;j <= p;j++)
		{
			if(ans[j] > 9)
			{
				ans[j+1] += ans[j]/10;
				ans[j] %= 10;
			}
		}
		if(ans[p+1])
			p++;
		for(int i = p;i < 100;i++)
		{
			if(ans[i] < 10)
			{
				p = i;
				break;
			}
			ans[i+1] += ans[i]/10;
			ans[i] %= 10;
		}
		for(int i = p;i >= 0;i--)
			printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}