#include <stdio.h>
int main()
{
	long long s, d;
	while(~scanf("%lld%lld", &s, &d))
	{
		double a = 1.0*d/s;
		long long ans;
		if(a>4)
			ans = 10*s-2*d;
		else if(a>3.0/2)
			ans = 8*s-4*d;
		else if(a>2.0/3)
			ans = 6*s-6*d;
		else if(a>1.0/4)
			ans = 3*s-9*d;
		else
			ans = -1;
		if(ans < 0)
			printf("Deficit\n");
		else
			printf("%lld\n", ans);
	}
	return 0;
}
