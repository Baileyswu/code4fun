#include <stdio.h>
int main()
{
	int t, p=0;
	long long n, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld", &n, &m);
		if(n > m)
		{
			n = n ^ m;
			m = n ^ m;
			n = n ^ m;
		}
		printf("Scenario #%d:\n%lld\n\n", ++p,(n+m)*(m-n+1)/2);
	}
	return 0;
}