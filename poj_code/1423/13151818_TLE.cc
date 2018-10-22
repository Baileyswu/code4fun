#include <stdio.h>
#include <math.h>
int main()
{
	int t, n;
	double sum;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		sum = 0;
		if(n == 0)
		{
			printf("1\n");
			continue;
		}
		while(n--)
			sum += log(n + 1);
		sum /= log(10);
		printf("%d\n", (int)sum + 1);
	}
	return 0;
}