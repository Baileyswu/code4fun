#include <stdio.h>
int a[50005];
int sel(int p, int q)
{
	int max = a[p], head = p, tail = p - 1, hi = 0;
	for(int i = p;i <= q;i++)
	{
		hi += a[i];
		tail++;
		if(hi < 0)
		{
			head = tail + 1;
			hi = 0;
		}
		if(hi > max)
			max = hi;
	}
	return max;
}
int main()
{
	int n, i, t, ans, tem;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%d", &a[i]);
		ans = a[0] + a[1];
		int max = a[0], head = 0, tail = -1, hi = 0;
		for(i = 0;i < n - 1;i++)
		{
			hi += a[i];
			tail++;
			if(hi > max)
				max = hi;
			tem = max + sel(i + 1, n - 1);
			if(tem > ans)
				ans = tem;
			if(hi < 0)
			{
				head = tail + 1;
				hi = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
