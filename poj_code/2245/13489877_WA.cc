#include <stdio.h>
#include <string.h>
int n, a[15], point[15], num;
bool flag[15];
int pr()
{
	int count = 0;
	for(int i = 0;i < n;i++)
	{
		if(flag[i])
		{
			printf("%d", a[i], count++);
			printf("%c", " \n"[count == 6]);
		}
	}
}
int dp(int k)
{
	int i;
	if(k == num)
	{
		if(point[k] > 0)
		{
			point[k]--;
			flag[point[k]] = 0;
			for(i = point[k] + 1;i < 7;i++)
				flag[i] = 1;
			for(i = 7;i < n;i++)
				flag[i] = 0;
			for(i = 1;i < num;i++)
				point[i] = n - i;
		}
		else
			point[k] = -1;
		return 0;
	}
	if(point[k] - point[k + 1] > 1)
	{
		flag[point[k]] = 1;	
		point[k]--;
		flag[point[k]] = 0;
		return 0;
	}
	dp(k + 1);
	return 0;
}
int main()
{
	int i, count = 0;
	while(scanf("%d", &n), n)
	{
		if(count)
			printf("\n");
		memset(flag, 1, sizeof(flag));
		for(i = 0;i < n;i++)
			scanf("%d", &a[i]);
		num = n - 6;
		for(i = 6;i < n;i++)
			flag[i] = 0;
		for(i = 1;i <= num;i++)
			point[i] = n - i;
		while(point[num] >= 0)
		{
			pr();
			dp(1);
		}
		count++;
	}
	return 0;
}