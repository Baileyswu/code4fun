#include <stdio.h>
#include <string.h>
#define N 500001
bool num[N] = {0};
long long ans[N];
int main()
{
	int m = 0;
	long long a = 0;
	num[0] = 1;
	while(m++ < N)
	{
		a -= m;
		if(a <= 0 || num[a])
			a += 2*m;
		num[a] = 1;
		ans[m] = a;
	}
	int k;
	while(scanf("%d", &k))
	{
		if(k == -1)
			break;
		printf("%lld\n", ans[k]);
	}
	return 0;
}
