#include <stdio.h>
#include <string.h>
int main()
{
	int t, n, ans;
	while(~scanf("%d", &ans))
	{
		t = 5;
		while(t--)
		{
			scanf("%d", &n);
			ans += n;
		}
		if(!ans)
			break;
		printf("%g\n", ans/6.0);
	}
	return 0;
}