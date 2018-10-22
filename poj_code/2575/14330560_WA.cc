#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int a, b, v = 0;
		scanf("%d", &a);
		for(int i = 1;i < n;i++)
		{
			scanf("%d", &b);
			if(!v && abs(a-b) >= n)
				v = 1;
			a = b;
		}
		if(v)
			printf("Not jolly\n");
		else
			printf("Jolly\n");
	}
	return 0;
}