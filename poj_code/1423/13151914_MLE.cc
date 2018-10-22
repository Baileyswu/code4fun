#include <stdio.h>
#include <math.h>
double ans[10000001];
int set()
{
	ans[0] = 0;
	ans[1] = 0;
	for(int i = 2;i < 10000001;i++)
		ans[i] = log(i) + ans[i - 1];
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
		sum = ans[n]/log(10) + 1;
		printf("%d\n", (int)sum);
	}
	return 0;
}