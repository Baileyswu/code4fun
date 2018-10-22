#include <stdio.h>
int main()
{
	int f[3];
	while(~scanf("%d%d%d", &f[0], &f[1], &f[2]))
	{
		double a = (f[0] + f[2])/2 - f[1], c = f[0];
		double b = f[1] - f[0] - a;
		printf("%.0f %.0f %.0f\n", 9*a+3*b+c,16*a+4*b+c,25*a+5*b+c);
	}
	return 0;
}