#include <stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, ans, k;
		scanf("%d", &n);
		if(n%2)
		{
			n = (n-1)/2;
			if(n%2)
			{
				k = (n-1)/2;
				ans = 4*k*k+4*k+1;
			}
			else
			{
				k = n/2;
				ans = 4*k*k;
			}
		}
		else
		{
			n = n/2;
			if((n-1)%2)
			{
				k = (n-2)/2;
				ans = 4*k*k+6*k+2;
			}
			else
			{
				k = (n-1)/2;
				ans = 4*k*k+2*k;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}