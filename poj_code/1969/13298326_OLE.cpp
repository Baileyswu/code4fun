#include <stdio.h>
#include <math.h>
int main()
{
	double x, n, ans, sum;
	while(scanf("%lf", &x))
	{
		n = ceil((sqrt(1+8*x)+1)/2) - 1;
		sum = n * (n - 1)/2;
		ans = x - sum;
		if(((int)n)%2)
			printf("TERM %d IS %d/%d\n", (int)x, (int)(n + 1 - ans), (int)ans);
		else
			printf("TERM %d IS %d/%d\n", (int)x, (int)ans, (int)(n + 1 - ans));
	}
	return 0;	
}