#include <stdio.h>
#include <math.h>
int ans[10000001];
int set()
{
	ans[0] = 0;
	ans[1] = 0;
	double s = 0;
	for(int i = 2;i < 10000001;i++)
	{
		s = (log(i) + s);
		ans[i] = (int)(s / log(10) + 1);
	}
	return 0;
}
int main()
{
	int t, n;
	double sum;
	scanf("%d", &t);
	set();
	while(t--)
	{
		scanf("%d", &n);
		sum = 0;
		if(n == 0)
		{
			printf("1\n");
			continue;
		}
		printf("%d\n", ans[n]);
	}
	return 0;
}