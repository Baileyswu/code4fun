#include <stdio.h>
#include <math.h>
int main()
{
	int r, x, y, four, count, digit[32], i = 0;
	scanf("%d,%d,%d", &r, &x, &y);
	while(i < 32)
	{
		four = r % 10;
		r /= 10;
		count = 4;
		while(count--)
		{
			digit[i++] = four & 1LL;
			four >>= 1;
		}
	}
	digit[x] = 0;
	digit[y] = 1, digit[y - 1] = 1, digit[y - 2] = 0;
	for(int i = 0;i < 32;i++)
		r += digit[i] * pow(2, i);
	printf("%0x\n", r);
	return 0;
}