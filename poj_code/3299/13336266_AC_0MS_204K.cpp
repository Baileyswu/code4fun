#include <stdio.h>
#include <math.h>
int main()
{
	char c1[2], c2[2];
	double t,d,h,e,hi;
	while(scanf("%s", c1) && c1[0] != 'E')
	{
		if(c1[0] == 'T')
			scanf("%lf", &t);
		else if(c1[0] == 'D')
			scanf("%lf", &d);
		else if(c1[0] == 'H')
			scanf("%lf", &h);
		scanf("%s",c2);
		if(c2[0] == 'T')
			scanf("%lf", &t);
		else if(c2[0] == 'D')
			scanf("%lf", &d);
		else if(c2[0] == 'H')
			scanf("%lf", &h);
		if((c1[0] == 'T' && c2[0] == 'D')||(c1[0] == 'D' && c2[0] == 'T'))
		{
			e = 6.11 * pow(2.718281828, (5417.7530 * ((1/273.16) - (1/(d+273.16)))));
			hi = (0.5555)* (e - 10.0);
			h = t + hi;
		}
		else if((c1[0] == 'H' && c2[0] == 'D')||(c1[0] == 'D' && c2[0] == 'H'))
		{
			e = 6.11 * pow(2.718281828, (5417.7530 * ((1/273.16) - (1/(d+273.16)))));
			hi = (0.5555)* (e - 10.0);
			t = h - hi;
		}
		else
		{
			hi = h - t;
			e = hi/0.5555 + 10.0;
			d = 1/((1/273.16)-log(e/6.11)/log(2.718281828) / 5417.7530)-273.16;
		}
		printf("T %.1lf D %.1lf H %.1lf\n", t, d, h);
	}
	return 0;
}