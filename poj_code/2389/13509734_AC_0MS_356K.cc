#include <stdio.h>
#include <string.h>
int main()
{
	char a[45], b[45];
	int x[45], y[45], z[100];
	while(~scanf("%s%s", a, b))
	{
		memset(z, 0, sizeof(z));
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		int xl = strlen(a), yl = strlen(b), i, j;
		for(i = 0;i < xl;i++)
			x[i] = a[xl - 1 - i] - '0';
		for(i = 0;i < yl;i++)
			y[i] = b[yl - 1 - i] - '0';
		int l = xl > yl ? xl : yl;
		for(i = xl;i < l;i++)
			x[i] = 0;
		for(i = yl;i < l;i++)
			y[i] = 0;
		for(i = 99;i >= 0;i--)
			if(z[i])
				break;
		for(j = 0;j < l;j++)
			for(i = 0;i < l;i++)
				z[i + j] += x[i] * y[j];
		for(i = 0;i < 100;i++)
		{
			if(z[i] >= 1000)
			{
				z[i + 3] += z[i] / 1000;
				z[i] %= 1000;
			}
			if(z[i] >= 100)
			{
				z[i + 2] += z[i] / 100;
				z[i] %= 100;
			}
			if(z[i] >= 10)
			{
				z[i + 1] += z[i] / 10;
				z[i] %= 10;
			}
		}
		for(i = 99;i >= 0;i--)
			if(z[i])
				break;
		if(i < 0)
			printf("0");
		for(;i >= 0;i--)
			printf("%d", z[i]);
		printf("\n");
	}
	return 0;
}