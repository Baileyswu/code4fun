# include <stdio.h>
long long ans(int a, int b, int M)
{
	if(!b)
		return 1;
	long long r = ans(a, b/2, M)%M;
	r = (r*r)%M;
	if(b & 1LL)
		r = (r*a)%M;
	return r;
}
int main()
{
	int t, M, H;
	scanf("%d", &t);
	while(t--)
	{
		int a, b;
		long long sum = 0;
		scanf("%d%d", &M, &H);
		while(H--)
		{
			scanf("%d%d", &a, &b);
			sum += ans(a, b, M);
			sum %= M;
		}
		printf("%lld\n", sum);
	}
	return 0;
}