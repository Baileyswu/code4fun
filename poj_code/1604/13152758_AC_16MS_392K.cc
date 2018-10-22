#include <stdio.h>
int ans[10000];
int set()
{
	ans[1] = 1;
	int s = 1;
	for(int i = 2;i < 10000;i++)
	{
		s *= i;
		while(s % 10 == 0)
			s /= 10;
		s %= 100000;
		ans[i] = s % 10 ;
	}
	return 0;
}
int main()
{
	int n;
	set();
	while(~scanf("%d", &n))
		printf("%5d -> %d\n", n, ans[n]);
	return 0;
}