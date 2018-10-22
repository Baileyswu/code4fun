#include <stdio.h>
int main()
{
	int zero, a, b, c;
	while(~scanf("%d%d%d%d", &zero, &a, &b, &c))
	{
		if(!zero && !a && !b && !c)
			break;
		a -= zero, b -= zero, c -= zero;
		if(a < 0) a += 40;
		while(b < a) b += 40;
		if(c < 0) c += 40;
		int ans = 120;
		ans += 40 - a;
		ans += b - a;
		c = b - c;
		while(c >= 40) c -= 40;
		while(c < 0) c += 40;
		ans += c;
		printf("%d\n", ans * 9);
	}
	return 0;
}