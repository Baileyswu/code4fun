#include <stdio.h>
#include <math.h>
int main()
{
	int x, y, digit[32], i = 0;
	long long r;
	scanf("%llx,%d,%d", &r, &x, &y);
	while(i < 32)
	{
		digit[i++] = r & 1LL;
		r >>= 1;
	}
	digit[x] = 0;
	digit[y] = 1, digit[y - 1] = 1, digit[y - 2] = 0;
	r = 0;
	for(int i = 0;i < 32;i++)
		r += digit[i] * pow(2, i);
	printf("%llx\n", r);
	return 0;
}