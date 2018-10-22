#include <stdio.h>
#include <math.h>
int a[10];
int rev(int n)
{
	int i = 0;
	while(n > 0)
	{
		a[i++] = n % 10;
		n /= 10;
	}
	int len = i, sum = 0;
	for(int i = 0;i < len;i++)
		sum += a[i] * (pow(10, len - 1 - i) + 0.000000001);
	return sum;
}
int main()
{
	int t, a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", rev(rev(a) + rev(b)));
	}
	return 0;
}