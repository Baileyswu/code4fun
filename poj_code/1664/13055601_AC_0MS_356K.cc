#include <stdio.h>
int divide(int n, int m, int l)
{
	if(m > n)
		return divide(n, n, l);
	if(m == 1 || n == l)
		return 1;
	int s = 1;
	for(int i = l;i <= n/2;i++)
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
		printf("%d\n", divide(n, m, 1));
	}
	return 0;
}