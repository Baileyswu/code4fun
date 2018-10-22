#include <stdio.h>
#include <string.h>
char pass[30];
int ok(int c)
{
	switch(c)
	{
		case 0:return 1;
		case 4:return 1;
		case 8:return 1;
		case 14:return 1;
		case 20:return 1;
	}
	return 0;
}
int pr(int d)
{
	if(d)
		printf("<%s> is acceptable.\n", pass);
	else
		printf("<%s> is not acceptable.\n", pass);
	return 0;
}
int main()
{
	char rep;
	int v, con, len, i, d, last;
	while(~scanf("%s", pass))
	{
		if(strcmp(pass, "end") == 0)
			break;
		len = strlen(pass);
		v = 0, con = 0, rep = 0, d = 0, last = -1;
		for(i = 0;i < len;i++)
		{
			if(ok(pass[i]-'a'))
			{
				if(!v)
					v = 1;
				if(last == 1)
					con++;
				else
					con = 1;
				if(con >= 3)
				{
					pr(0);
					d = 1;
					break;
				}
				last = 1;
			}
			else
			{
				if(!last)
					con++;
				else
					con = 1;
				if(con >= 3)
				{
					pr(0);
					d = 1;
					break;
				}
				last = 0;
			}
			if(pass[i] == rep && rep != 'e' && rep != 'o')
			{
				pr(0);
				d = 1;
				break;
			}
			else
				rep = pass[i];
		}
		if(!d && !v)
		{
			d = 1;
			pr(0);
		}
		if(!d)
			pr(1);
	}
	return 0;
}
