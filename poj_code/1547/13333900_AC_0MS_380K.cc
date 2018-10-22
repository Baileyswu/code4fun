#include <stdio.h>
int main()
{
	int n, at[9], i, a, b, c, sum;
	char st[9][10];
	while(scanf("%d", &n) && n != -1)
	{
		sum = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d%d%d%s", &a, &b, &c, st[i]);
			at[i] = a * b * c;
			sum += at[i];
		}
		sum /= n;
		for(i = 0;i < n;i++)
		{
			if(at[i] > sum)
				a = i;
			if(at[i] < sum)
				b = i;
		}
		printf("%s took clay from %s.\n", st[a], st[b]);
	}
}
