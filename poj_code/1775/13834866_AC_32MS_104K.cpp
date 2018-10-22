#include <stdio.h>

int main()
{
	int f[11] = {1};
	for(int i = 1;i < 11;i++)
		f[i] = f[i-1]*i;
	int n;
	while(~scanf("%d", &n))
	{
		if(n < 0)
			break;
		if(n == 0)
		{
			printf("NO\n");
			continue;
		}
		int p = 10;
		while(p >= 0)
		{
			if(f[p] <= n)
				n -= f[p];
			p--;
		}
		if(n == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
