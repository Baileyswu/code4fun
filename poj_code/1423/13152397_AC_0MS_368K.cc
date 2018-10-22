#include <stdio.h>
#include <math.h>
#define e 2.718281828459
#define Pi 3.1415926535898
int main()
{
	int t, n;
	double sum;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		if(n == 0 || n == 1)
		{
			printf("1\n");
			continue;
		}
		sum = log(2 * Pi * n)/log(10)/2 + n * log(n/e)/log(10) + 1;
		printf("%d\n", (int)sum);
	}
	return 0;
}