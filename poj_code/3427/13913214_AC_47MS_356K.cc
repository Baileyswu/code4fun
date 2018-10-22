#include <stdio.h>
int main()
{
	int n, k, m;
	while(~scanf("%d%d", &n, &k))
	{
		int ans = 0, l;
		while(n--)
		{
			scanf("%d", &l);
			m = l%k;
			if(m)
				m = k-m;
			if(ans < m)
				ans = m;
		}
		printf("%d\n", ans);
	}
}