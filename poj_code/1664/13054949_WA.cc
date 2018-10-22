#include <stdio.h>
int divide(int n, int m, int l)
{
	if(m == 1)
		return 1;
	int s = 0;
	for(int i = 1;i <= n/2;i++)
		s +=divide(n - i, m - 1, i);
	return s;
}
int main()
{
	int t, n, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", divide(n, m, 1) + 1);
	}
}