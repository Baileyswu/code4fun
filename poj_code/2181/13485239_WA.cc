#include <stdio.h>
#define N 150005
int a[N], n;
int find(int head, int tail)
{
	if(head >= tail)
		return 0; 	
	int maxx = a[head], minn = a[head], x = head, y = tail, i;
	for(i = head + 1;i <= tail;i++)
	{
		if(a[i] > maxx)
		{
			maxx = a[i];
			minn = a[i];
			x = i;
			y = i;
		}
		else
		{
			if(a[i] < minn)
			{
				minn = a[i];
				y = i;
			}
		}
	}
	if(x == n - 1 || y == n - 1)
		minn = 0;
	return maxx - minn + find(head, x - 1) + find(x + 1, y - 1) + find(y + 1, tail);
}
int main()
{
	while(~scanf("%d", &n))
	{
		for(int i = 0;i < n;i++)
			scanf("%d", &a[i]);
		int ans = find(0, n - 1);
		printf("%d\n", ans);
	}
	return 0;
}