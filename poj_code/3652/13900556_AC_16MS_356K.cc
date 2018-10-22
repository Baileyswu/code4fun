#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	int a, b, c, s, d, an[20], bn[20], la, lb, e, f;
	while(scanf("%d", &a), a)
	{
		scanf("%d%d%d", &b, &c, &s);
		memset(an, 0, sizeof(an));
		memset(bn, 0, sizeof(bn));
		d = (a*s+b)%c;
		la = lb = e = f = 0;
		int ss = s, dd = d;
		while(ss)
		{
			an[la++] = ss%2;
			ss /= 2;
		}
		while(dd)
		{
			bn[lb++] = dd%2;
			dd /= 2;
		}
		for(int i = 0;i < 16;i++)
			if(an[i] != bn[i])
				an[i] = -1, f++;
		while(s != d && e < c+2 && f < 16)
		{
			lb = 0;
			d = (a*d+b)%c;
			e++;
			dd = d;
			while(dd)
			{
				bn[lb++] = dd%2;
				dd /= 2;
			}
			for(int i = 0;i < 16;i++)
				if(an[i] >= 0 && an[i] != bn[i])
					an[i] = -1, f++;
		}
		for(int i = 15;i > -1;i--)
			if(an[i] < 0)
				printf("?");
			else
				printf("%d", an[i]);
		printf("\n");
	}
	return 0;
}