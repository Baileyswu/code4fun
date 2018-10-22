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
		printf("%.0lf %.0lf\n", n, ans);
		if(((int)n)%2)
			printf("TERM %.0lf IS %.0lf/%.0lf\n", x, n + 1 - ans, ans);
		else
			printf("TERM %.0lf IS %.0lf/%.0lf\n", x, ans, n + 1 - ans);
	}
	return 0;	
}