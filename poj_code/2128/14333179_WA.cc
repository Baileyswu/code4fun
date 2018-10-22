#include <stdio.h>
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int k, min_ = 1e9, p = 0, q, t;
		int k1, min_1 = 1e9;
		for(int i = 2;i <= n;i++)
		{
			scanf("%d", &q);
			t = q - p;
			p = q;
			if(t < min_)
			{
				min_ = t;
				k = i;
			}
			if(i > 2 && t < min_1)
			{
				min_1 = t;
				k1 = i;
			}
		}
		int sum = q;
		if(k == 2)
		{
			k = k1;
			sum += min_1;
		}
		else
			sum += min_;
		printf("%d\n%d 1 4 %d\n", sum, k, k-1);
	}
    return 0;
}