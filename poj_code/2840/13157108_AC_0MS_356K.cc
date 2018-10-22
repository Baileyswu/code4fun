#include <stdio.h>
int main()
{
	int t, h, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d:%d", &h, &m);
		if(m)
			printf("0\n");
		else if(h >= 0 && h < 13)
			printf("%d\n", h + 12);
		else
			printf("%d\n", h - 12);
	}
	return 0;
}