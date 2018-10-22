#include <stdio.h>
int main()
{
	int n, m, k;
	while(~scanf("%d%d%d", &n, &m, &k))
	{
		if(!n && !m && !k)
			break;
		int x = 0, y;
		for(int i = 2;i < n;i++)
			x = (m+x)%i;
		printf("%d\n", (x+k)%n+1);
	}
	return 0;
}
