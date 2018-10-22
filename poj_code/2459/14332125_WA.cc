#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_ 2005
int main()
{
	int c, st, re, D, num[max_];
	while(~scanf("%d%d%d%d", &c, &st, &re, &D))
	{
		memset(num, 0, sizeof(max_));
		int a, b, i;
		for(i = 0;i < c;i++)
		{
			scanf("%d%d", &a, &b);
			for(int j = a;j <= b;j++)
				num[j]++;
		}
		int po = 0; st -= re;
		for(i = D;i > 0;i--)
		{
			if(po == st)
				break;
			po += num[i];
		}
		printf("%d\n", i+1);
	}
	return 0;
}