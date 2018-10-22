#include <stdio.h>
#include <string.h>
int main()
{
	char c;
	while((c = getchar()) != EOF)
	{
		int d;
		switch(c - 'A' + 1)
		{
			case -17:d = -18;break;
			case -18:d = -20;break;
			case -20:d = 13;break;
			case 13:d = 14;break;
			case 14:d = 2;break;
			case 2:d = 22;break;
			case 22:d = 3;break;
			case 3:d = 24;break;
			case 24:d = 26;break;
			case -25:d = -5;break;
			case -5:d = 12;break;
			case 12:d = 11;break;
			case 11:d = 10;break;
			case 10:d = 8;break;
			case 8:d = 7;break;
			case 7:d = 6;break;
			case 6:d = 4;break;
			case 4:d = 19;break;
			case 19:d = 1;break;
			case 28:d = 29;break;
			case 29:d = 27;break;
			case 27:d = 16;break;
			case 16:d = 15;break;
			case 15:d = 9;break;
			case 9:d = 21;break;
			case 21:d = 25;break;
			case 25:d = 20;break;
			case 20:d = 18;break;
			case 18:d = 5;break;
			case 5:d = 23;break;
			case 23:d = 17;break;
			default:d = c - 'A' + 1;break;
		}
		c = d - 1 + 'A';
		if(c >= '2' && c <= '9')
			c -= 1;
		else if(c == '0')
			c = '9';
		else if(c == '-')
			c = '0';
		else if(c == '=')
			c = '-';
		else if(c == '1')
			c = '`';
		printf("%c", c);
	}
	return 0;
}