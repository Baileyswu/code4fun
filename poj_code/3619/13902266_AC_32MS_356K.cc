#include <stdio.h>
int main()
{
	int K, N, S, T, R, sum;
	while(~scanf("%d%d", &K, &N))
	{
		while(N--)
		{
			scanf("%d%d%d", &S, &T, &R);
			int tim = K/S;
			if(K%S)
				tim++;
			int l = tim/T;
			if(tim%T)
				tim += l*R;
			else
				tim += (l-1)*R;
			printf("%d\n", tim);
		}
	}
	return 0;
}