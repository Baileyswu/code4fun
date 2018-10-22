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
	if(k > num)
	{
		point[num] = -1;
		return 0;
	}
	if(point[k] - point[k + 1] > 1)
	{
		point[k]--;
		flag[point[k]] = 0;
		for(i = point[k] + 1;i < n - k + 1;i++)
			flag[i] = 1;
		for(i = n - k + 1;i < n;i++)
			flag[i] = 0;
		for(i = 1;i < k;i++)
			point[i] = n - i;
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
		point[num + 1] = -1;
		while(point[num] >= 0)
		{
			pr();
			dp(1);
		}
		count = 1;
	}
	return 0;
}