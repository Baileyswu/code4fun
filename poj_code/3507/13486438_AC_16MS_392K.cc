#include <stdio.h>
#include <string.h>
int main()
{
	int t, n, ans, min, max;
	while(~scanf("%d", &ans))
	{
		min = ans, max = ans;
		t = 5;
		while(t--)
		{
			scanf("%d", &n);
			if(n < min)
				min = n;
			if(n > max)
				max = n;
			ans += n;
		}
		if(!ans)
			break;
		ans -= min + max;
		printf("%g\n", ans/4.0);
	}
	return 0;
}