#include <stdio.h>
int main()
{
	double start, pre;
	scanf("%lf", &start);
	if(start == 999.0)
	{
		printf("End of Output\n");
		return 0;
	}
	while(scanf("%lf", &pre) && pre != 999.0)
	{
		printf("%.2lf\n", pre - start);
		start = pre;
	}
	printf("End of Output\n");
	return 0;
}