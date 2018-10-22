#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int r = 1, ans = 1;
		while(r != 0)
		{
			r *= 10;
			r++;
			r %= n;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}