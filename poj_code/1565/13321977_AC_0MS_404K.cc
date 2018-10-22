#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char num[50];
	int sum, len;
	while(scanf("%s", num) && num[0] != '0')
	{
		sum = 0;
		len = strlen(num);
		for(int i = 0;i < len;i++)
			sum += (pow(2, len - i) - 1) * (num[i] - '0');
		printf("%d\n", sum);
	}
	return 0;
}