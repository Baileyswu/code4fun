#include <stdio.h>
int main()
{
	long long a, b, c, km, di;
	int k;
	while(scanf("%lld%lld%lld%d", &a, &b, &c, &k), !(!a&&!b&&!c&&!k))
	{
		km = 1, di = 0;
		for(int i = 0;i < k;i++)
			km *= 2;
		if(b - a < 0)
			b += km*((a-b)/km+1);
		if(km % c == 0)
		{
			if((b-a)%c)
				printf("FOREVER\n");
			else
				printf("%lld\n", (b-a)/c);
		}
		else
		{
			if((b-a)%c)
			{
				int v = 0, i;
				for(i = 0;i < c;i++)
				{
					if((i*km+b-a)%c==0)
					{
						v = 1;
						break;
					}
				}
				if(v)
					printf("%ll\n", (i*km+b-a)/c);
				else
					printf("FOREVER\n");
			}
			else
				printf("%lld\n", (b-a)/c);
		}
	}
	return 0;
}