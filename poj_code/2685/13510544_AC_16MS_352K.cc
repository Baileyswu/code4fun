#include <stdio.h>
#include <string.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char a[10], b[10];
		scanf("%s%s", a, b);
		int xl = strlen(a), yl = strlen(b), i, x = 0, y = 0;
		for(i = xl - 1;i >= 0;i--)
		{
			if(a[i] == 'i')
			{
				if(i - 1 >= 0 && a[i-1] >= '2' && a[i-1] <= '9')
				{
					x += a[i-1]-'0';
					i--;
				}
				else
					x += 1;
			}
			else if(a[i] == 'x')
			{
				if(i - 1 >= 0 && a[i-1] >= '2' && a[i-1] <= '9')
				{
					x += (a[i-1]-'0')*10;
					i--;
				}
				else
					x += 10;
			}
			else if(a[i] == 'c')
			{
				if(i - 1 >= 0 && a[i-1] >= '2' && a[i-1] <= '9')
				{
					x += (a[i-1]-'0')*100;
					i--;
				}
				else
					x += 100;
			}
			else if(a[i] == 'm')
			{
				if(i - 1 >= 0 && a[i-1] >= '2' && a[i-1] <= '9')
				{
					x += (a[i-1]-'0')*1000;
					i--;
				}
				else
					x += 1000;
			}
		}
		for(i = yl - 1;i >= 0;i--)
		{
			if(b[i] == 'i')
			{
				if(i - 1 >= 0 && b[i-1] >= '2' && b[i-1] <= '9')
				{
					y += b[i-1]-'0';
					i--;
				}
				else
					y += 1;
			}
			else if(b[i] == 'x')
			{
				if(i - 1 >= 0 && b[i-1] >= '2' && b[i-1] <= '9')
				{
					y += (b[i-1]-'0')*10;
					i--;
				}
				else
					y += 10;
			}
			else if(b[i] == 'c')
			{
				if(i - 1 >= 0 && b[i-1] >= '2' && b[i-1] <= '9')
				{
					y += (b[i-1]-'0')*100;
					i--;
				}
				else
					y += 100;
			}
			else if(b[i] == 'm')
			{
				if(i - 1 >= 0 && b[i-1] >= '2' && b[i-1] <= '9')
				{
					y += (b[i-1]-'0')*1000;
					i--;
				}
				else
					y += 1000;
			}
		}
		x = x + y;
		y = x / 1000;
		if(y == 1)
			printf("m");
		else if(y > 1)
			printf("%dm", y);
		x %= 1000;
		y = x / 100;
		if(y == 1)
			printf("c");
		else if(y > 1)
			printf("%dc", y);
		x %= 100;
		y = x / 10;
		if(y == 1)
			printf("x");
		else if(y > 1)
			printf("%dx", y);
		x %= 10;
		y = x;
		if(y == 1)
			printf("i");
		else if(y > 1)
			printf("%di", y);
		printf("\n");
	}
	return 0;
}