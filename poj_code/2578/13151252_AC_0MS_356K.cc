#include <stdio.h>
int main()
{
	int a[3], v = 0;
	for(int i = 0;i < 3;i++)
	{
		scanf("%d", &a[i]);
		if(a[i] <= 168)
		{
			printf("CRASH %d\n", a[i], v = 1);
			break;
		}
	}
	if(v == 0)
		printf("NO CRASH\n");
	return 0;
}