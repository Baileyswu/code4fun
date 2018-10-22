#include <stdio.h>
#include <string.h>
int main()
{
	char c, f;
	int d, e, v = 0;
	while((c = getchar())!= EOF)
	{
		if(v)
			if(f == c)
				continue;
		if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='H'||c=='W'||c=='Y')
			continue;
		if(c=='\n')
			printf("\n");
		else if(c=='B'||c=='F'||c=='P'||c=='V')
			d = 1;
		else if(c=='C'||c=='G'||c=='J'||c=='K'||c=='Q'||c=='S'||c=='X'||c=='Z')
			d = 2;
		else if(c=='D'||c=='T')
			d = 3;
		else if(c=='L')
			d = 4;
		else if(c=='M'||c=='N')
			d = 5;
		else if(c=='R')
			d = 6;
		printf("%d", d);
		f = c;
		v = 1;
	}
	return 0;
}