#include <stdio.h>
int main()
{
	long long a, x, A, min, i;
	while(~scanf("%lld", &a))
	{
		A = a * a + 1;
		min = A + 1 + 2 * a;
		for(i = a;i >= 1;i--)
			if(A % i == 0)
				break;
		x = i + A / i + 2 * a;
		if(x < min)
			min = x;
		printf("%lld\n", min);
	}

	return 0;
}