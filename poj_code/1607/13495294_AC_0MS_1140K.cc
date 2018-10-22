#include <stdio.h>
#define N 100000
int main()
{
	double ans[N] = {0};
	int i;
	for(i = 1;i < N;i++)
		ans[i] = ans[i - 1] + 1/(2.0 * i);
	int n;
	printf("Cards  Overhang \n");
	while(~scanf("%d", &n))
		printf("%5d     %.3f\n", n, ans[n]);
	return 0;
}