#include <stdio.h>
#include <math.h>
int main()
{
	int x, sum, t;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d", &x) && x)
	{
		sum = 1;
		t = sqrt(x);
		for(int i = 2;i <= t;i++)
			if(x % i == 0)
				sum += i + x/i;
		if(t * t == x)
			sum -= t;
		t = sum - x;
		if(!t)
			printf("%5d  PERFECT\n", x);
		else if(t>0)
			printf("%5d  ABUNDANT\n", x);
		else
			printf("%5d  DEFICIENT\n", x);
	}
	printf("END OF OUTPUT\n");
	return 0;
}