#include <stdio.h>
#include <string.h>
int a, b, c, d, e, f, g, h, find[1005];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int i, j, s;
		scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
		find[0] = a, find[1]= b, find[2] = c;
		for(j = 3;j <= i;j++)
		{	
			if(j & 1LL)
			{
				s = (d*find[j-1]+e*find[j-2]-f*find[j-3])%g;
				if(s < 0)
					s += g;
				find[j] = s;
			}
			else
			{
				int s = (f*find[j-1]-d*find[j-2]+e*find[j-3])%h;
				if(s < 0) 
					s += h;
				find[j] = s;
			}
		}
		printf("%d\n", find[i]);
	}
	return 0;
}