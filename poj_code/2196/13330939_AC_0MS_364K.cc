#include <stdio.h>
int n;
int di(int k)
{
	int tem = n, s = 0;
	for(int i = 0;i < 4;i++)
	{
		s += tem % k;
		tem /= k;
	}
	return s;
}
int main()
{
	int a, b, c;
    for(n = 2992;n < 10000;n++)
    {
    	a = di(10);
    	b = di(16);
    	c = di(12);
    	if(a == b && a == c)
    		printf("%d\n", n);
    }
    return 0;
}