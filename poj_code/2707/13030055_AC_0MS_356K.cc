#include<stdio.h>
int main()
{
	int a,b,c,d,rate,t;
	while( scanf( "%d %d %d %d", &a, &b, &c, &d) != EOF && a!=0)
	{
		if( a > b )
		{
			t = a;
			a = b;
			b = t;
		}
		if( c > d )
		{
			t = c;
			c = d;
			d = t;
		}
		if( a <= c && b <= d )
			rate = 100;
		else if( a > c && b <= d)
			rate = 100 * c / a;
		else if( a <= c && b > d )
			rate = 100 * d / b;
		else
			rate = 100 * d / b < 100 * c / a ? 100 * d / b: 100 * c / a;
		printf("%d%%\n", rate);
	}
	return 0;

}
