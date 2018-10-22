#include <stdio.h>
#include <math.h>
int main()
{
	int a, x, A, t, min;
	while(~scanf("%d", &a))
	{
		A = a * a + 1;
		t = sqrt(A);
		min = A + 1 + 2 * a;
		for(int i = 1;i <= t;i++)
		{
			if(A % i == 0)
			{
				x = i + A / i + 2 * a;
				if(x < min)
					min = x;
			}
		}
		printf("%d\n", min);
	}

	return 0;
}