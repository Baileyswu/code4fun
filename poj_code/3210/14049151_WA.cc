#include <stdio.h>
int main()
{
	int t;
	while(scanf("%d", &t), t)
	{
		if(t%2==0)
			printf("No Solution!\n");
		else if(t == 3)
			printf("2\n");
		else
			printf("%d\n", t-2);
	}
	return 0;
}