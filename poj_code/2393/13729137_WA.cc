#include <stdio.h>
#include <string.h>
int main()
{
	int n, s, i;
	while(~scanf("%d%d", &n,&s))
	{
		int c, y, mimi = 101;
		long long ans =0;
		while(n--)
		{
			mimi += s;
			scanf("%d%d", &c, &y);
			if(mimi > c)
				mimi = c;
			ans += mimi*y;
		}
		printf("%lld\n", ans);
	}
	return 0;
}