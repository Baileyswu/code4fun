#include <stdio.h>
int main()
{
	int f[11] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
	int n;
	while(~scanf("%d", &n))
	{
		if(n < 0)
			break;
		if(!n)
		{
			printf("NO\n");
			continue;
		}
		int p = 11, i, q;
		while(n > 0)
		{
			q = p;
			for(i = 0;i <= p;i++)
			{
				if(n < f[i])
				{
					p = i-1;
					break;
				}
			}
			if(p == q)
				break;
			n -= f[p];
			//printf("%d %d\n", p, f[p]);
		}
		if(!n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}