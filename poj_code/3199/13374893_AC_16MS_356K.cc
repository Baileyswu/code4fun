#include <stdio.h>
int main()
{
	int n, d;
	while(scanf("%d%d", &n, &d), n)
	{
		if(d == 0)
		{
			printf("1\n");
			continue;
		}
		int i, re[27] = {n}, t, start;
		d--;
		while(d--)
		{
			for(i = 0;i < 27;i++)
				re[i] *= n;
			for(i = 0;i < 27;i++)
			{
				t = re[i]/10;
				re[i] %= 10;
				re[i + 1] += t;
			}
		}
		for(i = 26;i >= 0;i--)
		{
			if(re[i])
			{
				start = i;
				break;
			}
		}
		for(i = start;i >= 0;i--)
			printf("%d", re[i]);
		printf("\n");
	}
	return 0;
}