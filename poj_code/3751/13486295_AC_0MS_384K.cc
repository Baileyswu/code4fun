#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int y, m, d, a, b, c;
		char p[3];
		while(n--)
		{
			scanf("%d/%d/%d-%d:%d:%d", &y, &m, &d, &a, &b, &c);
			if(a >= 0 && a < 12)
			{
				strcpy(p, "am");
				if(!a)
					a = 12;
			}
			else
			{
				strcpy(p, "pm");
				if(a != 12)
					a -= 12;
			}
			printf("%02d/%02d/%d-%02d:%02d:%02d%s\n", m, d, y, a, b, c, p);
		}
	}
	return 0;
}