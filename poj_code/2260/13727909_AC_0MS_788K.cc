#include <stdio.h>
#include <string.h>
int a[1000][1000];
int pr()
{
	printf("ok\n");
}
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		int x = 0, y = 0, i, j, sum, ai, aj;
		for(i = 0;i < n;i++)
			for(j = 0;j < n;j++)
				scanf("%d", &a[i][j]);
		for(i = 0;i < n;i++)
		{
			sum = 0;
			for(j = 0;j < n;j++)
				sum += a[i][j];
			if(sum&1LL)
			{
				x++;
				ai = i;
			}
			if(x > 1)
			{
				printf("Corrupt\n");
				break;
			}
		}
		//pr();
		if(x > 1)
			continue;
		for(j = 0;j < n;j++)
		{
			sum = 0;
			for(i = 0;i < n;i++)
				sum += a[i][j];
			if(sum&1LL)
			{
				y++;
				aj = j;
			}
			if(y > 1)
			{
				printf("Corrupt\n");
				break;
			}
		}
		if(y > 1)
			continue;
		if(!x && !y)
			printf("OK\n");
		else if(x && y)
			printf("Change bit (%d,%d)\n", ai+1, aj+1);
		else
			printf("Corrupt\n");
	}
	return 0;
}