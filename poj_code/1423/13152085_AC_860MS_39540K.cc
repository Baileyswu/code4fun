#include <stdio.h>
#include <math.h>
int ans[10000001];
int set()
{
	ans[0] = 1;
	ans[1] = 1;
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
		printf("%d\n", ans[n]);
	}
	return 0;
}