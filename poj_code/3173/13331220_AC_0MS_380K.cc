#include <stdio.h>
int main()
{
	int n, s, a[211], i, j, head, k;
	scanf("%d%d", &n, &s);
	for(i = 1;i <= n * (n + 1)/2;i++)
		a[i] = (s + i - 2) % 9 + 1;
	for(j = 1;j <= n;j++)
	{
		for(i = 0;i < j - 1;i++)
			printf("  ");
		head = j*(j+1)/2;
		printf("%d", a[head]);
		k = j;
		for(int i = 2;i <= n + 1 - j;i++)
		{
			head += k++;
			printf(" %d", a[head]);	
		}
		printf("\n");
	}
	return 0;
}