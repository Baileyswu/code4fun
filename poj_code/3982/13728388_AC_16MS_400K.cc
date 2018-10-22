#include <stdio.h>
#include <string.h>
int s[3][100], p, co[3][100], q[3], ans[100];
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
	int x[3];
	while(~scanf("%d%d%d", &x[0], &x[1], &x[2]))
	{
		memset(s, 0, sizeof(s));
		p = 0;
		for(int i = 0;i < 3;i++)
			s[i][0] = x[i];
		set();
		for(int i = p;i >= 0;i--)
			printf("%d", s[0][i]);
		printf("\n");
	}
	return 0;
}