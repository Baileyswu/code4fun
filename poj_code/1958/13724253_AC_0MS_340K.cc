#include <stdio.h>
#include <math.h>
int f[15] = {0, 1}, g[15] = {0,1,3,5};
int main()
{
	int i, k, temp;
	for(i = 1;i < 13;i++)
		f[i+1] = 2*f[i] + 1;
	for(i = 4;i < 13;i++)
	{
		int min = 100000000;
		for(k = 2;k <= i;k++)
		{
			temp = 2*g[i-k]+f[k];
			if(temp < min)
				min = temp;
		}
		g[i] = min;
	}
	for(i = 1;i < 13;i++)
		printf("%d\n", g[i]);
	return 0;
}
