#include <stdio.h>
#include <string.h>
int main()
{
	int n, s, i;
	while(~scanf("%d%d", &n,&s))
	{
		int ans = 0, mon, wei, mimi = 101;
		while(n--)
		{
			mimi += s;
			scanf("%d%d", &mon, &wei);
			if(mimi > mon)
				mimi = mon;
			ans += mimi*wei;
		}
		printf("%d\n", ans);
	}
	return 0;
}