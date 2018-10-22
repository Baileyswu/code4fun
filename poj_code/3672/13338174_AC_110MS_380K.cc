#include <stdio.h>
int main()
{
	int m, t, u, f, d, sum = 0, p = 0;
	char co[2];
	scanf("%d%d%d%d%d", &m, &t, &u, &f, &d);
	while(t--)
	{
		scanf("%s", co);
		if(sum > m)
			continue;
		if(co[0] == 'f')
			sum += 2 * f;
		else
			sum += u + d;
		p++;
	}
	if(sum <= m)
		p++;
	printf("%d\n", --p);
	return 0;
}