#include <stdio.h>
int a[100000];
int main()
{
	int t, n, sum, i, min, j, hi, head, tail, tem;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &sum);
		min = n + 1;
		hi = 0, head = 0, tail = -1;
		for(i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
			hi += a[i];
			tail++;
			while(hi >= sum)
			{
				tem = tail - head + 1;
				if(tem < min)
					min = tem;
				hi -= a[head++];
			}
		}
		if(min > n)
			min = 0;
		printf("%d\n", min);
	}
	return 0;
}