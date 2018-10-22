#include <stdio.h>
int main()
{
	int n, p, i, j, a[100][100], min, max, count, v, ans;
	scanf("%d%d", &n, &p);
	for(i = 0;i < n;i++)
	{
		min = 1001, max = -1;
		for(j = 0;j < p;j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] > max)
				max = a[i][j];
			if(a[i][j] < min)
				min = a[i][j];
		}
		for(j = 0;j < p;j++)
		{
			if(a[i][j] == min)
				a[i][j] = -1;
			else if(a[i][j] == max)
				a[i][j] = 1001;
			else
				a[i][j] = 0;
		}
	}
	for(j = 0;j < p;j++)
	{
		v = 0;
		count = 0;
		for(i = 0;i < n;i++)
		{
			if(a[i][j] == 1001)
			{
				v = 1;
				break;
			}
			if(a[i][j] == -1)
				count++;
		}
		if(v)
			continue;
		if(count > n/2)
		{
			ans++;
			printf("%d ", j + 1);
		}
	}
	if(!ans)
			printf("0\n");
	return 0;
}