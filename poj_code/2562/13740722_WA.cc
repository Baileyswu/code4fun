#include <stdio.h>
#include <string.h>
int main()
{
	char a[100], b[100];
	int an[100], bn[100], i, j;
	while(~scanf("%s%s", &a, &b))
	{
		if(a[0] == '0' && b[0] == '0')
			break;
		int c = 0;
		int al = strlen(a), bl = strlen(b);
		for(i = 0;i < al;i++)
			an[i] = a[al-1-i] - '0';
		for(j = 0;j < bl;j++)
			bn[j] = b[bl-j-1] - '0';
		int l = al>bl?al:bl;
		for(;i < l;i++)
			an[i] = 0;
		for(;j < l;j++)
			bn[j] = 0;
		for(i = 0;i < l;i++)
			if(an[i] + bn[i] > 9)
			{
				c++;
				if(i+1 < l)
					an[i+1]++;
			}
		if(c)
			printf("%d", c);
		else
			printf("No");
		printf(" carry operation.\n");
	}
	return 0;
}