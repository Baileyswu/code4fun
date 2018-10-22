#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int flag[3005];
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int a, b, v = 0, t;
		scanf("%d", &a);
		memset(flag, 0, sizeof(flag));
		for(int i = 1;i < n;i++)
		{
			scanf("%d", &b);
			if(v)
				continue;
			int t = abs(a-b);
			if ( t >= n || a == b )
				v = 1;
			else
				flag[t] = 1;
			a = b;
		}
		if(v)
		{
			printf("Not jolly\n");
			continue;
		}
		for(int i = 1;i < n;i++)
		{
			if(!flag[i])
			{
				v = 1;
				break;
			}
		}
		if(v)
			printf("Not jolly\n");
		else
			printf("Jolly\n");
	}
	return 0;
}