#include <stdio.h>
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int k, min_ = 1e9, p = 0, q, t;
		for(int i = 2;i <= n;i++)
		{
			scanf("%d", &q);
			t = q - p;
			p = q;
			if(i > 2 && i < 4 && t < min_)
			{
				min_ = t;
				k = i;
			}
		}
		if(n < 4)
		{
			printf("0\n");
			continue;
		}
		int sum = q + min_;
		printf("%d\n%d 1 %d %d\n", sum, k, n, k-1);
	}
    return 0;
}